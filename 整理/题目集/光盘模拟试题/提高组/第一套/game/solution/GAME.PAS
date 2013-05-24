{$R+}
program Game;
const
  maxsize=20000;
  dx:array[1..4] of shortint=(0,-1,1,0);
  dy:array[1..4] of shortint=(1,0,0,-1);
type
  aa=array[0..maxsize] of word;
  b128=array[0..255] of boolean;
  b65k=array[0..255] of ^b128;
var
  time0:longint;
  time:longint absolute $40:$6C;
  found:boolean;
  next,s,p:^aa;
  sx1,sy1,sx2,sy2:^aa;
  h,d:array[0..maxsize] of byte;
  g,dst:array[1..4,1..4] of shortint;
  list:^aa;
  mark:b65k;

  cur,tail:integer;
  nsrc,ndst:word;

  function GraphicToWord:word;
  var i,j:integer;
      su:word;
  begin
    su:=0;
    for i:=4 downto 1 do
      for j:=4 downto 1 do su:=su*2+g[i,j];
    GraphicToWord:=su;
  end;

  procedure WordToGraphic(x:word);
  var i,j:integer;
  begin
    for i:=1 to 4 do
     for j:=1 to 4 do
       begin
         g[i,j]:=x mod 2;
         x:=x div 2;
       end;
  end;

  procedure Init;
  var i,j:integer;
      st:string[4];
  begin
    time0:=time;
    assign(input,'game.in');
    reset(input);
    for i:=1 to 4 do
      begin
        readln(st);
        for j:=1 to 4 do if st[j]='1' then g[i,j]:=1;
      end;
    nsrc:=GraphicToWord;
    readln(st);
    for i:=1 to 4 do
      begin
        readln(st);
        for j:=1 to 4 do if st[j]='1' then dst[i,j]:=1;
      end;
    g:=dst;
    ndst:=GraphicToWord;
    new(sx1);
    new(sy1);
    new(sx2);
    new(sy2);
    fillchar(sx1^,sizeof(sx1^),0);
    fillchar(sx2^,sizeof(sx2^),0);
    fillchar(sy1^,sizeof(sy1^),0);
    fillchar(sy2^,sizeof(sy2^),0);
    new(next);
    new(s);
    new(p);
    for i:=0 to 255 do
      begin
        new(mark[i]);
        fillchar(mark[i]^,sizeof(mark[i]^),0);
      end;

    fillchar(next^,sizeof(next^),0);
    fillchar(s^,sizeof(s^),0);
    fillchar(p^,sizeof(p^),0);
  end;

  procedure Out;
  var u,v:integer;
      i,k:integer;
      len:integer;
  begin
    writeln('Tail=',tail);
    writeln('Time=',(time-time0)/18.2:0:2,'s');
    assign(output,'Game.out');
    rewrite(output);
    new(list);
    fillchar(list^,sizeof(list^),0);
    u:=tail;
    len:=0;
    while(u<>0) do
    begin
      v:=u;
      u:=p^[v];
      inc(len);
      list^[len]:=v;
    end;
    writeln(len);
    for i:=len downto 1 do
      begin
        k:=list^[i];
        writeln(sx1^[k],' ',sy1^[k],' ',sx2^[k],' ',sy2^[k]);
      end;
    close(output);
  end;


  function GuJia:integer;
  var i,j:integer;
      k:integer;
  begin
    k:=0;
    for i:=1 to 4 do
      for j:=1 to 4 do
{        if (g[i,j]=0) and (dst[i,j]=1) then inc(k);}
     if g[i,j]<>dst[i,j] then inc(k);
    Gujia:=k;
  end;

  procedure Insert;
  var p,q:integer;
  begin
    q:=cur;
    repeat
      p:=q;
      q:=next^[p];
    until (h[tail]<h[q]) or (q=0);
    next^[tail]:=q;
    next^[p]:=tail;
  end;

  function check:boolean;
  var i,j:integer;
  begin
    if mark[s^[tail] div 256]^[s^[tail] mod 256] then check:=false else check:=true;
  end;

  procedure Expand;
  var i,j:integer;
      k,l:integer;
      x,y:integer;
  begin
    WordToGraphic(s^[cur]);
    for i:=1 to 4 do
      for j:=1 to 4 do
        if g[i,j]=1 then
          for k:=1 to 4 do
            begin
              x:=i+dx[k];
              y:=j+dy[k];
              if (x in [1..4]) and (y in [1..4]) and (g[x,y]=0) then
                begin
                  g[i,j]:=0;
                  g[x,y]:=1;
                  inc(tail);
                  s^[tail]:=GraphicToWord;
                  if (not check) then dec(tail) else
                    begin
                      d[tail]:=d[cur]+1;
                      h[tail]:=GuJia+d[tail] div 2;
                      p^[tail]:=cur;
                      sx1^[tail]:=i;
                      sy1^[tail]:=j;
                      sx2^[tail]:=x;
                      sy2^[tail]:=y;
                      Insert;
                      Mark[s^[tail] div 256]^[s^[tail] mod 256]:=true;
                      if ndst=s^[tail] then
                        begin
                          found:=true;
                          exit;
                        end;
                    end;
                  g[i,j]:=1;
                  g[x,y]:=0;
                end;
            end;
  end;

  procedure Main;
  var i,j:integer;
  begin
    s^[cur]:=nsrc;
    mark[nsrc div 256]^[nsrc mod 256]:=true;
    found:=false;
    if nsrc<>ndst then
    repeat
      cur:=next^[cur];
      expand;
    until (found) or (next^[cur]=0) or (tail>=maxsize);
  end;

  begin
    Init;
    Main;
    Out;
  end.