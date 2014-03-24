var
 i,k:integer;
 ans:int64;
begin
 assign(input,'hanoi.in');
 reset(input);
 assign(output,'hanoi.out');
 rewrite(output);
 readln(i);
 for k:=1 to i do
  begin
   if k=1 then ans:=1
    else
     begin
      ans:=ans*2;
      ans:=ans+1;
     end;
  end;
 writeln(ans);
 close(input);
 close(output);
end.
