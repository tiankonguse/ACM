var     p:array[1..10,1..2]of longint;
        l:array[1..10,1..10,1..3]of longint;
        a:array[1..10,1..10,1..10,1..10]of boolean;
        i1,i2,j1,j2,t,n:longint;
        f:array[1..10]of boolean;
        w:array[0..10]of longint;
procedure search(s:longint);
var     i,j:longint;
        g:boolean;
begin
        if s=n then
        begin
                inc(t);
                exit;
        end;
        for i:=1 to n do
        if (not f[i]) or (s=n-1) then
        begin
                g:=true;
                for j:=1 to s-1 do
                if (s<>n-1) or (j<>1) then if not a[w[s],i,w[j-1],w[j]] then g:=false;
                if g then
                begin
                        f[i]:=true;
                        w[s+1]:=i;
                        search(s+1);
                        f[i]:=false;
                end;
        end;
end;
begin
        assign(input,'lines.in');
        reset(input);
        assign(output,'lines.out');
        rewrite(output);
        repeat
                inc(n);
                read(p[n,1],p[n,2]);
        until (p[n,1]=0) and (p[n,2]=0);
        for i1:=1 to n do
                for i2:=1 to n do
                if i1<>i2 then
                begin
                        l[i1,i2,1]:=p[i2,2]-p[i1,2];
                        l[i1,i2,2]:=p[i1,1]-p[i2,1];
                        l[i1,i2,3]:=p[i2,1]*p[i1,2]-p[i1,1]*p[i2,2];
                end;
        for i1:=1 to n do
        for i2:=1 to n do
        if i1<>i2 then
                for j1:=1 to n do
                for j2:=1 to n do
                if j1<>j2 then
                begin
                        a[i1,i2,j1,j2]:=false;
                        if (l[j1,j2,1]*p[i1,1]+l[j1,j2,2]*p[i1,2]+l[j1,j2,3])*
                           (l[j1,j2,1]*p[i2,1]+l[j1,j2,2]*p[i2,2]+l[j1,j2,3])>0 then a[i1,i2,j1,j2]:=true;
                        if (l[i1,i2,1]*p[j1,1]+l[i1,i2,2]*p[j1,2]+l[i1,i2,3])*
                           (l[i1,i2,1]*p[j2,1]+l[i1,i2,2]*p[j2,2]+l[i1,i2,3])>0 then a[i1,i2,j1,j2]:=true;
                end;
        w[0]:=1;
        f[1]:=true;
        search(0);
        writeln(t div 2);
        close(input);
        close(output);
end.
