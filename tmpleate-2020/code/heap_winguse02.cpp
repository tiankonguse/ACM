/*************************************************************************
    > File Name: heap_winguse02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/18 19:48:48
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include <ctime>
#include <cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
#include <cassert>
using namespace std;

#define INPUT_FILE "Gtest.txt"
//#define DEBUG_MODE
//#define ASSERT_ON

typedef long long ll;

const int MAX_INT = ((unsigned)(-1) >> 1);
const int MIN_INT = (~MAX_INT);

//const int MAX_EDGE = 40010;
//const int MAX_VERTEX = 20010;
const int POPULATION = 10;
const int lr = 1000000;//;
const int cr = 3000;//;
const int alpha = 15;
const int gama = 200;
const int tenureParts = 15;
const int tenureInterval = 100;
const int tenure[tenureParts] = {1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1};
const double beta = 0.6;

struct Heap { /// greater

	std::vector<int> h;
	std::vector<int> pos;
	std::vector<int> &org;
	int size;
	Heap(std::vector<int> &__org): org(__org) {
		size = 0;
		h.resize(org.size());
		pos.resize(org.size(), 0);
	}
	void clear() {
		for(int i = 1; i <= size; i++) {
			pos[h[i]] = 0;
		}
		size = 0;
	}
	void up(int orgIdx) {
		int idx = pos[orgIdx];
#ifdef ASSERT_ON
		if(idx < 1 || idx > size) {
			printf("orgIdx = %d, idx = %d, size = %d\n", orgIdx, idx, size);
			for(int i = 1; i <= idx; i++) {
				printf("%3d", h[i]);
			}
		}
		assert(idx >= 1 && idx <= size);
#endif
		while(idx > 1 && org[h[idx>>1]] < org[h[idx]]) {
			std::swap(h[idx], h[idx>>1]);
			pos[h[idx]] = idx;
			idx >>= 1;
			pos[h[idx]] = idx;
		}
	}
	void down(int orgIdx) {
		int idx = pos[orgIdx];
#ifdef ASSERT_ON
		assert(idx >= 1 && idx <= size);
#endif
		while(true) {
			if((idx << 1 | 1) <= size && org[h[idx<<1|1]] > org[h[idx]] && org[h[idx<<1|1]] > org[h[idx<<1]]) {
				std::swap(h[idx<<1|1] , h[idx]);
				pos[h[idx]] = idx;
				idx <<= 1;
				idx |= 1;
				pos[h[idx]] = idx;
			} else if((idx << 1) <= size && org[h[idx<<1]] > org[h[idx]]) {
				std::swap(h[idx<<1] , h[idx]);
				pos[h[idx]] = idx;
				idx <<= 1;
				pos[h[idx]] = idx;
			} else {
				break;
			}
		}
	}
	void insert(int orgIdx) {
		size++;
		h[size] = orgIdx;
		pos[orgIdx] = size;
		up(orgIdx);
	}
	void del(int orgIdx) {
		int value = org[orgIdx], idx = pos[orgIdx];
#ifdef ASSERT_ON
		assert(idx >= 1 && idx <= size);
#endif
		pos[orgIdx] = 0;
		if(idx == size) {
			size--;
			return;
		}
		h[idx] = h[size--];
		pos[h[idx]] = idx;
		if(org[h[idx]] < value)
			down(h[idx]);
		else
			up(h[idx]);
	}
	bool update(int orgIdx, int value) {
		if(pos[orgIdx] == 0) {
			return false;
		}
		if(org[orgIdx] < value) {
			org[orgIdx] = value;
			down(orgIdx);
		} else {
			org[orgIdx] = value;
			up(orgIdx);
		}
		return true;
	}
	bool updateDeta(int orgIdx, int deta) {
		if(deta == 0)return true;
		if(pos[orgIdx] == 0) {
			return false;
		}
		org[orgIdx] += deta;
		if(deta < 0) {
			down(orgIdx);
		} else {
			up(orgIdx);
		}
		return true;
	}
	int getTop() {
#ifdef ASSERT_ON
		assert(size > 0);
		for(int i = 1; i <= size; i++) {
			assert(org[h[1]] >= org[h[i]]);
		}
#endif
		return h[1];
	}
};

struct Edge {
	int v;
	int weight;
	int next;
};

int V, E;
std::vector<Edge> edges;//无向图
//std::vector<std::vector<int> > matrix;
int edgeIdx;
std::vector<int> head;

struct Unit {
	std::vector<bool> inSet;
	int fitness;
	void init() {
		inSet.resize(V + 1);
		fitness = MIN_INT;
	}
	int getFitness() {//对于仅仅移动确定边的稀疏图，这个应该可以优化
		if(fitness == MIN_INT) {
			fitness = 0;
			for(int i = 1; i <= V; i++) {
				if(!inSet[i])continue;
				for(int j = head[i]; j != -1; j = edges[j].next) {
					//	printf("%d %d\n",j,edges[j].v);
					if(inSet[edges[j].v])continue;
					fitness += edges[j].weight;
				}
			}
		}
		return fitness;
	}
};

std::vector<Unit> population;
Unit best;

void insertEdge(const int u, const int v, const int weight) {
	edges[edgeIdx].v = v;
	edges[edgeIdx].weight = weight;
	edges[edgeIdx].next = head[u];
	head[u] = edgeIdx++;
//	matrix[u][v] = weight;
}

void input() {
	int u, v, w;
	scanf("%d%d", &V, &E);
	edges.resize(E << 1 | 1);
	head.resize(V + 1, -1);
//	matrix.resize(V + 1);
//	for(int i = 0; i <= V; i++) {
//		matrix[i].resize(V + 1);
//	}
	edgeIdx = 0;
	for(int i = 0; i < E; i++) {
		scanf("%d%d%d", &u, &v, &w);
		insertEdge(u, v, w);
		insertEdge(v, u, w);
	}
}

void initPopulation() {
	population.resize(POPULATION);
	for(int i = 0; i < POPULATION; i++) {
		population[i].init();
		int m = V >> 1;
		std::fill(population[i].inSet.begin() + 1, population[i].inSet.begin() + m + 1, true);
		std::fill(population[i].inSet.begin() + m + 2, population[i].inSet.end(), false);
		std::random_shuffle(population[i].inSet.begin() + 1, population[i].inSet.end());
	}
}

void selectBest() {
	int bestIdx = 0;
	for(int i = 1; i < POPULATION; i++) {
		if(population[i].getFitness() > population[bestIdx].getFitness())
			bestIdx = i;
	}
	best = population[bestIdx];
}


void tabuSearch(Unit &unit) {
	int localBest = unit.getFitness();
	std::vector<int> detaV;
	std::vector<bool> tabuList;
	detaV.resize(unit.inSet.size());
	tabuList.resize(unit.inSet.size(), false);
	Heap h1(detaV), h0(detaV);// these two heaps storage the best vertex not in tabu list
	Heap h0T(detaV);//this heap storage the best vertex in the false list in the tabu list
	/// compute the move gain detaV
	for(int i = 1; i <= V; i++) {
		detaV[i] = 0;
#ifdef DEBUG_MODE
		printf("%d -> ", i);
#endif
		for(int j = head[i]; j != -1; j = edges[j].next) {
#ifdef DEBUG_MODE
			printf("%3d(%d)", edges[j].v, edges[j].weight);
#endif
			if(unit.inSet[edges[j].v] == unit.inSet[i]) {
#ifdef DEBUG_MODE
				printf("add");
#endif
				detaV[i] += edges[j].weight;
			} else {
#ifdef DEBUG_MODE
				printf("dec");
#endif
				detaV[i] -= edges[j].weight;
			}
#ifdef DEBUG_MODE
			printf("%3d", detaV[i]);
#endif
		}
#ifdef DEBUG_MODE
		puts("");
#endif
		if(unit.inSet[i]) {
			h1.insert(i);
		} else {
			h0.insert(i);
		}
	}
#ifdef DEBUG_MODE
	{
		printf("tabu: ");
		for(int i = 1; i <= V; i++)
			if(tabuList[i])
				printf("%4d", i);
		puts("");
		printf("true:\t");
		for(int i = 1; i <= V; i++)
			if(unit.inSet[i])
				printf("%4d", i);
		puts("");
		printf("detaV:\t");
		for(int i = 1; i <= V; i++)
			if(unit.inSet[i])
				printf("%4d", detaV[i]);
		puts("");
		printf("false:\t");
		for(int i = 1; i <= V; i++)
			if(!unit.inSet[i])
				printf("%4d", i);
		puts("");
		printf("detaV:\t");
		for(int i = 1; i <= V; i++)
			if(!unit.inSet[i])
				printf("%4d", detaV[i]);
		puts("");
		int tmpFitness = unit.fitness;
		unit.fitness = MIN_INT;
		printf("%d %d\n", tmpFitness, unit.getFitness());
		assert(tmpFitness == unit.getFitness());
	}
#endif
	///iter < lr , notImproved < cr
	for(int iter = 0, notImproved = 0, tenureIdx = 0, intervalIter = 0, flushIter = 0, flushInterval = alpha * tenure[tenureIdx]; iter < lr; iter++) {
		if(iter % (lr / 10) == 0) {
			printf("\rtabu %2d%% bestFitness = %d", iter * 100 / lr, best.getFitness());
			//fflush(stdout);
		}
#ifdef DEBUG_MODE
		puts("- - - - - - - - - -");
#endif
		/// select the best on the true list
		int v1 = h1.getTop();//堆里面有可能是负数的，这个时候考虑跳出优化？
		/// move v to another side, from true side to false side
#ifdef DEBUG_MODE
		printf("move %d to false side\n", v1);
#endif
		h1.del(v1);
		unit.fitness += detaV[v1]; /** ?? 这里 fitness 的增量应该就是 detaV 吧 **/
		detaV[v1] = -detaV[v1];
		unit.inSet[v1] = false;
		/// add v1 to tabu list
		tabuList[v1] = true;
		h0T.insert(v1); //insert it in the tabu list's heap
		///update detaV
		for(int i = head[v1]; i != -1; i = edges[i].next) {
#ifdef DEBUG_MODE
			printf("%d -> %d ", v1, edges[i].v);
#endif
			if(unit.inSet[edges[i].v]) {
#ifdef DEBUG_MODE
				printf("dec %d\n", edges[i].weight);
#endif
				if(!h1.updateDeta(edges[i].v, -(edges[i].weight << 1)))
					detaV[edges[i].v] += -(edges[i].weight << 1);
			} else {
#ifdef DEBUG_MODE
				printf("add %d\n", edges[i].weight);
#endif
				if(!h0.updateDeta(edges[i].v, edges[i].weight << 1))
					if(!h0T.updateDeta(edges[i].v, edges[i].weight << 1))
						assert(false);
			}
		}
#ifdef DEBUG_MODE
		{
			printf("tabu: ");
			for(int i = 1; i <= V; i++)
				if(tabuList[i])
					printf("%4d", i);
			puts("");
			printf("true:\t");
			for(int i = 1; i <= V; i++)
				if(unit.inSet[i])
					printf("%4d", i);
			puts("");
			printf("detaV:\t");
			for(int i = 1; i <= V; i++)
				if(unit.inSet[i])
					printf("%4d", detaV[i]);
			puts("");
			printf("false:\t");
			for(int i = 1; i <= V; i++)
				if(!unit.inSet[i])
					printf("%4d", i);
			puts("");
			printf("detaV:\t");
			for(int i = 1; i <= V; i++)
				if(!unit.inSet[i])
					printf("%4d", detaV[i]);
			puts("");
		}
#endif
#ifdef ASSERT_ON
		int tmpFitness = unit.fitness;
		unit.fitness = MIN_INT;
#ifdef DEBUG_MODE
		printf("tmpFitness = %d, unit.getFitness() = %d\n", tmpFitness, unit.getFitness());
#endif
		assert(tmpFitness == unit.getFitness());
#endif


		/// select the best in the false list
		int v0 = h0.getTop();
		int v0T = h0T.getTop();
		if(h0T.size > 0 && detaV[v0] < detaV[v0T] && unit.fitness + detaV[v0T] > best.getFitness()) { //毫无疑问选v0T
			v0 = v0T;
			h0T.del(v0T);
		} else { //选v0
			h0.del(v0);
		}
#ifdef DEBUG_MODE
		printf("move %d to true side\n", v0);
#endif
		/// generate new solution
		unit.fitness += detaV[v0];
		detaV[v0] = -detaV[v0];
		unit.inSet[v0] = true;
		/// add v0 to tabu list
		tabuList[v0] = true;
		/// update detaV
		for(int i = head[v0]; i != -1; i = edges[i].next) {
#ifdef DEBUG_MODE
			printf("%d -> %d ", v0, edges[i].v);
#endif
			if(unit.inSet[edges[i].v]) {
#ifdef DEBUG_MODE
				printf("add %d\n", edges[i].weight);
#endif
				if(!h1.updateDeta(edges[i].v, edges[i].weight << 1))
					detaV[edges[i].v] += edges[i].weight << 1;
			} else {
#ifdef DEBUG_MODE
				printf("dec %d\n", edges[i].weight);
#endif
				if(!h0.updateDeta(edges[i].v, -(edges[i].weight << 1)))
					if(!h0T.updateDeta(edges[i].v, -(edges[i].weight << 1)))
						assert(false);
			}
		}
#ifdef DEBUG_MODE
		{
			printf("tabu: ");
			for(int i = 1; i <= V; i++)
				if(tabuList[i])
					printf("%4d", i);
			puts("");
			printf("true:\t");
			for(int i = 1; i <= V; i++)
				if(unit.inSet[i])
					printf("%4d", i);
			puts("");
			printf("detaV:\t");
			for(int i = 1; i <= V; i++)
				if(unit.inSet[i])
					printf("%4d", detaV[i]);
			puts("");
			printf("false:\t");
			for(int i = 1; i <= V; i++)
				if(!unit.inSet[i])
					printf("%4d", i);
			puts("");
			printf("detaV:\t");
			for(int i = 1; i <= V; i++)
				if(!unit.inSet[i])
					printf("%4d", detaV[i]);
			puts("");
			int tmpFitness = unit.fitness;
			unit.fitness = MIN_INT;
			printf("tmpFitness = %d, unit.getFitness() = %d\n", tmpFitness, unit.getFitness());
			assert(tmpFitness == unit.getFitness());
		}
#endif
		if(unit.getFitness()>localBest){
			notImproved = 0;
			localBest = unit.getFitness();
			if(unit.getFitness() > best.getFitness()) {
				best = unit;
			}
		} else {
			notImproved++;
		}
		intervalIter++;
		if(intervalIter == tenureInterval) {
			flushIter = 0;
			intervalIter = 0;
			tenureIdx++;
			if(tenureIdx == tenureParts)
				tenureIdx = 0;
			flushInterval = alpha * tenure[tenureIdx];
		}
		flushIter++;
		/** !! all member is in tabu list **/
		if(h1.size == 0 || h0.size == 0) {
#ifdef DEBUG_MODE
			printf("all member is in tabu list # %d %d\n", h1.size, h0.size);
#endif
			flushIter = flushInterval;
		}
		if(notImproved == cr) {
#ifdef DEBUG_MODE
			printf("not improved clear tabu before perturb\n");
#endif
			flushIter = flushInterval;
		}
		if(flushIter == flushInterval) {
			for(int j = 1; j <= V; j++) {
				if(!tabuList[j])continue;
				tabuList[j] = false;
				if(unit.inSet[j]) {
					h1.insert(j);
				} else {
					h0.insert(j);
				}
			}
			h0T.clear(); //clear heap of tabu
			flushIter = 0;
		}
		if(notImproved == cr) {
			///perturb
#ifdef DEBUG_MODE
			puts("perturb");
#endif
			for(int i = 0; i < gama; i++) {
#ifdef DEBUG_MODE
				{
					printf("tabu: ");
					for(int i = 1; i <= V; i++)
						if(tabuList[i])
							printf("%4d", i);
					puts("");
					printf("true:\t");
					for(int i = 1; i <= V; i++)
						if(unit.inSet[i])
							printf("%4d", i);
					puts("");
					printf("detaV:\t");
					for(int i = 1; i <= V; i++)
						if(unit.inSet[i])
							printf("%4d", detaV[i]);
					puts("");
					printf("false:\t");
					for(int i = 1; i <= V; i++)
						if(!unit.inSet[i])
							printf("%4d", i);
					puts("");
					printf("detaV:\t");
					for(int i = 1; i <= V; i++)
						if(!unit.inSet[i])
							printf("%4d", detaV[i]);
					puts("");
					int tmpFitness = unit.fitness;
					unit.fitness = MIN_INT;
					printf("tmpFitness = %d, unit.getFitness() = %d\n", tmpFitness, unit.getFitness());
					assert(tmpFitness == unit.getFitness());
				}
#endif
				//select two vertex
				int idx1 = (ll)(rand()) * h1.size / ((ll)(RAND_MAX) + 1) + 1;
				assert(idx1 > 0 && idx1 <= h1.size);
				int idx0 = (ll)(rand()) * h0.size / ((ll)(RAND_MAX) + 1) + 1;
				assert(idx0 > 0 && idx0 <= h0.size);
				if(idx0 > h0.size)idx0 = h0.size;
				int selectV1 = h1.h[idx1];
				int selectV0 = h0.h[idx0];
#ifdef DEBUG_MODE
				printf("%d <--> %d\n", selectV1, selectV0);
#endif
				//move from true side to false side
#ifdef DEBUG_MODE
				puts("true --> false");
#endif
				h1.del(selectV1);
				unit.fitness += detaV[selectV1];
				detaV[selectV1] = -detaV[selectV1];
				unit.inSet[selectV1] = false;
				h0.insert(selectV1);
				for(int j = head[selectV1]; j != -1; j = edges[j].next) {
#ifdef DEBUG_MODE
					printf("%d -> %d ", selectV1, edges[j].v);
#endif
					if(unit.inSet[edges[j].v]) {
#ifdef DEBUG_MODE
						printf("dec %d\n", edges[j].weight);
#endif
						if(!h1.updateDeta(edges[j].v, -(edges[j].weight << 1)))
							detaV[edges[j].v] += -(edges[j].weight << 1);
					} else {
#ifdef DEBUG_MODE
						printf("add %d\n", edges[j].weight);
#endif
						if(!h0.updateDeta(edges[j].v, edges[j].weight << 1))
							if(!h0T.updateDeta(edges[j].v, edges[j].weight << 1))
								assert(false);
					}
				}
				//move from false side to true side
#ifdef DEBUG_MODE
				puts("false --> true");
#endif
				h0.del(selectV0);
				unit.fitness += detaV[selectV0];
				detaV[selectV0] = -detaV[selectV0];
				unit.inSet[selectV0] = true;
				h1.insert(selectV0);
				for(int j = head[selectV0]; j != -1; j = edges[j].next) {
#ifdef DEBUG_MODE
					printf("%d -> %d ", selectV0, edges[j].v);
#endif
					if(unit.inSet[edges[j].v]) {
#ifdef DEBUG_MODE
						printf("add %d\n", edges[j].weight);
#endif
						if(!h1.updateDeta(edges[j].v, edges[j].weight << 1))
							detaV[edges[j].v] += edges[j].weight << 1;
					} else {
#ifdef DEBUG_MODE
						printf("dec %d\n", edges[j].weight);
#endif
						if(!h0.updateDeta(edges[j].v, -(edges[j].weight << 1)))
							if(!h0T.updateDeta(edges[j].v, -(edges[j].weight << 1)))
								assert(false);
					}
				}
			}
			notImproved = 0;
		}
#ifdef DEBUG_MODE
		puts("# # # # #");
#endif
	}
}

Unit crossOver(Unit &Ii, Unit &Ij) {
	Unit I0;
	I0.init();
	int trueCount = 0;
	for(int i = 1; i <= V; i++) {
		if(Ii.inSet[i] && Ij.inSet[i])
			trueCount++;
	}
	if(trueCount <= (V >> 2)) {
#ifdef DEBUG_MODE
		puts("In reverse");
#endif
		trueCount = (V >> 1) - trueCount;
#ifdef ASSERT_ON
		int __trueCount = 0;
#endif
		for(int i = 1; i <= V; i++) {
			Ij.inSet[i] = !Ij.inSet[i];
#ifdef ASSERT_ON
			if(Ii.inSet[i] && Ij.inSet[i])
				__trueCount++;
#endif
		}
#ifdef ASSERT_ON
		assert(__trueCount == trueCount);
#endif
	}
	std::vector<int> trueList, falseList, notSureList;
	std::vector<bool> inTrue, inFalse, notSure;
	inTrue.resize(V + 1, false);
	inFalse.resize(V + 1, false);
	notSure.resize(V + 1, false);
	for(int i = 1; i <= V; i++) {
		if(Ii.inSet[i] && Ij.inSet[i]) {
			trueList.push_back(i);
			inTrue[i] = true;
		} else if(!Ii.inSet[i] && !Ij.inSet[i]) {
			falseList.push_back(i);
			inFalse[i] = true;
		} else {
			notSureList.push_back(i);
			notSure[i] = true;
		}
	}
	std::vector<int> putTrueWeight, putFalseWeight;
	int notSureSize = notSureList.size();
	putTrueWeight.resize(V + 1, 0);
	putFalseWeight.resize(V + 1, 0);
	for(int i = 0; i < notSureSize; i++) {
		int u = notSureList[i];
		for(int j = head[u]; j != -1; j = edges[j].next) {
			int v = edges[j].v;
			if(inTrue[v]) {
				putFalseWeight[u] += edges[j].weight;
			} else if(inFalse[v]) {
				putTrueWeight[u] += edges[j].weight;
			}
		}
	}
	Heap hTrue(putTrueWeight), hFalse(putFalseWeight);
	for(int i = 0; i < notSureSize; i++) {
		hTrue.insert(notSureList[i]);
		hFalse.insert(notSureList[i]);
	}
#ifdef DEBUG_MODE
	printf("TrueList:\t");
	for(int i = 1; i <= V; i++) {
		if(inTrue[i])
			printf("%3d", i);
	}
	puts("");
	printf("FalseList:\t");
	for(int i = 1; i <= V; i++) {
		if(inFalse[i])
			printf("%3d", i);
	}
	puts("");
	printf("NotSureList:\t");
	for(int i = 1; i <= V; i++) {
		if(notSure[i])
			printf("%3d", i);
	}
	puts("");
	printf("PutTrueW:\t");
	for(int i = 1; i <= V; i++) {
		if(notSure[i])
			printf("%3d", putTrueWeight[i]);
	}
	puts("");
	printf("PutFalseW:\t");
	for(int i = 1; i <= V; i++) {
		if(notSure[i])
			printf("%3d", putFalseWeight[i]);
	}
	puts("");
#endif
	for(int i = 0; i < notSureSize; i += 2) {
		/// insert on the true side ///
		int u = hTrue.getTop();
		inTrue[u] = true;
		notSure[u] = false;
		hTrue.del(u);
		hFalse.del(u);
		for(int j = head[u]; j != -1; j = edges[j].next) {
			int v = edges[j].v;
			if(notSure[v]) {
				hTrue.updateDeta(v, edges[j].weight);
			}
		}
		/// insert on the false side ///
		u = hFalse.getTop();
		inFalse[u] = true;
		notSure[u] = false;
		hTrue.del(u);
		hFalse.del(u);
		for(int j = head[u]; j != -1; j = edges[j].next) {
			int v = edges[j].v;
			if(notSure[v]) {
				hFalse.updateDeta(v, edges[j].weight);
			}
		}
	}
#ifdef ASSERT_ON
	int trueCnt = 0, falseCnt = 0;
#endif
	for(int i = 1; i <= V; i++) {
		I0.inSet[i] = inTrue[i];
#ifdef ASSERT_ON
		if(inTrue[i])
			trueCnt++;
		if(inFalse[i])
			falseCnt++;
		assert(inTrue[i] != inFalse[i]);
#endif
	}
#ifdef ASSERT_ON
	assert(trueCnt == falseCnt);
#endif
	I0.getFitness();
	return I0;
}

void poolUpdate() {
	int size = population.size();
	std::vector<int> distance;
	std::vector<double> goodness;
	int  dMax = MIN_INT, dMin = MAX_INT;
	int  fMax = MIN_INT, fMin = MAX_INT;
	distance.resize(size);
	goodness.resize(size);
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(i == j)continue;
			distance[i] = 0;
			for(int k = 1; k <= V; k++) {
				if(population[i].inSet[k] != population[j].inSet[k]) {
					distance[i]++;
				}
			}
		}
		if(distance[i] >= (V >> 1))
			distance[i] = V - distance[i];
		if(dMin > distance[i])
			dMin = distance[i];
		if(dMax < distance[i])
			dMax = distance[i];
		if(fMin > population[i].getFitness())
			fMin = population[i].getFitness();
		if(fMax < population[i].getFitness())
			fMax = population[i].getFitness();
	}
	int dDenominator = dMax - dMin + 1;
	int fDenominator = fMax - fMin + 1;
	int worst = 0;
	for(int i = 0; i < size; i++) {
		goodness[i] = beta * (population[i].getFitness() - fMin) / fDenominator + (1 - beta) * (distance[i] - dMin) / dDenominator;
		if(i > 0 && goodness[worst] > goodness[i])
			worst = i;
	}
	if(worst != size - 1) {
		population[worst] = population[size-1];
	}
	population.pop_back();
}

int main() {
//	freopen(INPUT_FILE, "r", stdin);
#ifdef DEBUG_MODE
	puts("Debug mode.");
#else
	srand(time(NULL));
#endif
	input();
	puts("input terminated");
	initPopulation();
	puts("init population terminated");
	selectBest();
	puts("initial select best terminated");
	for(int i = 0; i < POPULATION; i++) {
		tabuSearch(population[i]);
		printf("\rI%d tabu search finished, final fitness = %5d, best fitness = %5d\n", i + 1, population[i].getFitness(), best.getFitness());
	}
	puts("initial tabu search terminted");
	for(int it = 0; it < lr; it++) { ///
		int i = (ll)(rand()) * POPULATION / ((ll)(RAND_MAX) + 1);
		int j = i;
		while(i == j) {
			j = (ll)(rand()) * POPULATION / ((ll)(RAND_MAX) + 1);
		}
		Unit I0 = crossOver(population[i], population[j]);
		tabuSearch(I0);
		printf("\rinterval #%3d: I0 fitness = %d, best fitness = %d\n", it, population[i].getFitness(), best.getFitness());
		if(I0.getFitness() > best.getFitness())
			best = I0;
		population.push_back(I0);
		poolUpdate();
	}
	return 0;
}
