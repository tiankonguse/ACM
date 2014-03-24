program test2_3;
var expstr,newexp:string;
    s:array [1..255] of char;
    opcode:array[1..255] of 0..3;
    p,len,i:byte;
    ch:char;
    res:array[1..255] of longint;

procedure trans_exp;
var i:byte;
 procedure access_oprator;
 var fg:byte; flag:boolean;
 begin
   case ch of
     '+','-':fg:=1;
     '*','/':fg:=2;
     '^':fg:=3;
   end;
   flag:=false;
   repeat
    if (p=0) or ((p>0) and (opcode[p]<fg))  then
      begin
       p:=p+1;
       s[p]:=ch;
       opcode[p]:=fg;
       flag:=true;
      end
      else
       while (p>0) and (opcode[p]>=fg) do
        begin
         newexp:=newexp+s[p];
         p:=p-1;
        end;
    until flag
  end;
  procedure access_left;
  begin
   p:=p+1;
   s[p]:=ch;
   opcode[p]:=0;
  end;
  procedure access_right;
  begin
  if p=0 then begin writeln('error');halt(1) end;
  while s[p]<>'(' do  begin  newexp:=newexp+s[p];p:=p-1 end;
  p:=p-1;
  end;
begin
 for i:=1 to len do
 begin
  ch:=expstr[i];
  case ch of
   '0'..'9': newexp:=newexp+ch;
   '+','-','*','/','^': access_oprator;
   '(':access_left;
   ')':access_right;
  end;
 end;
 while p>0 do
 begin newexp:=newexp+s[p];p:=p-1; end;
end;

procedure work;
var t:longint; i,j,k:integer;
begin
 for i:=1 to length(newexp) do
  begin
	if i<length(newexp) then write(newexp[i],' ') else writeln(newexp[i]);
	if pos(newexp[i],'0123456789')>0 then res[i]:=ord(newexp[i])-ord('0');
	end;
 while length(newexp)>1 do
	begin
	 i:=3;
	 while pos(newexp[i],'+-*/^')=0 do inc(i);
	 case newexp[i] of
		 '+': res[i-2]:=res[i-2]+res[i-1];
		 '-': res[i-2]:=res[i-2]-res[i-1];
		 '*': res[i-2]:=res[i-2]*res[i-1];
		 '/': res[i-2]:=res[i-2] div res[i-1];
		 '^': begin
					 t:=res[i-2];
					 for j:=2 to res[i-1] do res[i-2]:=t*res[i-2];
					end;
	 end;
	 delete(newexp,i-1,2);
	 for j:=1 to i-2 do
		if length(newexp)>1 then	write(res[j],' ') else writeln(res[j]);
	 for j:=i-1 to length(newexp) do
		begin
		 if j<length(newexp) then write(newexp[j],' ') else writeln(newexp[j]);
		 if pos(newexp[j],'0123456789')>0 then  res[j]:=ord(newexp[j])-ord('0');
		end;
	end;
end;

begin {main}
 assign(input,'express.in');reset(input);
 readln(expstr);  len:=length(expstr);  close(input);
 assign(output,'express.out'); rewrite(output);
 trans_exp;
 work;
 close(output);
end.
