program heart;
const h:array [1..13] of longint
        =(-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40);
var i,j,p,point,total:longint;
    ch:char;
    pig,sheep,d:boolean;
    score:array [1..4] of longint;
begin
     assign(input,'heart.in');
     reset(input);
     assign(output,'heart.out');
     rewrite(output);
     repeat
           total:=0;
           for i:=1 to 4 do
           begin
                score[i]:=0;
                pig:=false;
                sheep:=false;
                d:=false;
                read(p);
                total:=total+p;
                for j:=1 to p do
                begin
                     repeat
                           read(ch);
                     until ch>='A';
                    { write(ch);}
                     read(point);
                     case ch of
                     'S':pig:=true;
                     'H':score[i]:=score[i]+h[point];
                     'D':sheep:=true;
                     'C':d:=true
                     end;
                    { write(point,' ')}
                end;
                readln;
                if (p=1) and d
                   then score[i]:=50
                   else if score[i]<>-194
                           then begin if pig then score[i]:=score[i]-100;
                                      if sheep then score[i]:=score[i]+100;
                                      if d then score[i]:=score[i]*2
                                end
                           else begin
                                     score[i]:=200;
                                     if pig and sheep
                                        then score[i]:=500
                                        else begin
                                             if pig then score[i]:=score[i]-100;
                                             if sheep then score[i]:=score[i]+100
                                             end;
                                     if d then score[i]:=score[i]*2
                                end;

           end;
           if total<>0 then
           begin
                for i:=1 to 4 do
                begin
                     if score[i]>0 then write('+');
                     write(score[i]);
                     if i<4 then write(' ')
                end;
                writeln
           end
     until total=0;
     close(input);
     close(output);
end.

