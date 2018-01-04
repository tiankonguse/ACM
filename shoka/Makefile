all: main.pdf

main.pdf: main.tex main.aux
	xelatex -shell-escape main.tex

main.aux: main.tex
	xelatex -shell-escape main.tex
