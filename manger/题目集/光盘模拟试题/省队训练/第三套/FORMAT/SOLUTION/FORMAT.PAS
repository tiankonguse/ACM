{
  CTU Open Contest 2002
  =====================
  Sample solution for the problem: format

  Martin Kacer, Oct 2002
}

Program Formatting;

Const MAXWORDS = 10200;
	PENALTY = 500;
	MAXLINE = 128;

Var Len: Array [1..MAXWORDS] of Integer;
	Best: Array [0..MAXWORDS] of Integer;
	WordCount: Integer;


{compute the lowest badness for the 'Row' characters long row
with 'Num' words (Num>2) with a total length of 'Len' (Len<=Row-Num+1)}
Function CountBadness (Row, Len, Num: Integer) : Integer;
Var SpLen, SpBig: Integer;
Begin
	Dec (Num);   {number of spaces between words}
	SpLen := (Row - Len) div Num;
	SpBig := (Row - Len) - (SpLen * Num);

	{now we have Num spaces;
	'SpBig' of them are 'SpLen+1' character long;
	the other are 'SpLen' characters long}
	CountBadness := (SpLen-1) * (SpLen-1) * (Num - SpBig)
		+ SpLen * SpLen * SpBig;
End; { CountBadness }


{remember a solution for the first 'Cnt' words (badness given),
if no better has been found before}
Procedure Possible (Cnt: Integer; Badness: Integer);
Begin
	If (Best[Cnt] < 0) or (Badness < Best[Cnt]) then
		Best[Cnt] := Badness;
End; { Possible }


{solve one problem, iterate word by word}
Function FindBest (Row: Integer) : Integer;
Var I, J, Sum: Integer;
Begin
	For I := 0 to WordCount do Best[I] := -1;
	Best[0] := 0;
	For I := 0 to WordCount-1 do
		If Len[I+1] = Row then
			Possible (I+1, Best[I])
		else Begin
			Possible (I+1, Best[I] + PENALTY);
			Sum := Len[I+1];
			J := I+1;
			Repeat
				Inc (J);
				Sum := Sum + Len[J];
				If (Sum + (J-I-1) <= Row) and (J <= WordCount) then
					Possible (J, Best[I] + CountBadness (Row, Sum, J-I));
			until (Sum + (J-I-1) >= Row) or (J >= WordCount);
		End;
	FindBest := Best [WordCount];
End; { FindBest }


{read the text and remember word lengths}
Procedure ReadText;
Var S: String[MAXLINE];
	I, J: Integer;
Begin
	WordCount := 0;
	Repeat
		ReadLn (S);
		I := 1;
		While (I <= Length(S)) do
		Begin
			While (I <= Length(S)) and (S[I] = ' ') do Inc (I);
			J := I;
			While (I <= Length(S)) and (S[I] <> ' ') do Inc (I);
			If (J < I) then
			Begin
				Inc (WordCount);
				Len [WordCount] := I - J;
			End;
		End;
	until Length(S) = 0;
End; { ReadText }


Var Row : Integer;

Begin
	Repeat
		ReadLn (Row);
		If (Row > 0) then
		Begin
			ReadText;
			WriteLn ('Minimal badness is ',FindBest (Row),'.');
		End;
	until (Row = 0);
End.

