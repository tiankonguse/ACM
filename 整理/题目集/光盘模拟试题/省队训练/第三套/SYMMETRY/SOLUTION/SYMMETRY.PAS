{
  CTU Open Contest 2002
  =====================
  Sample solution for the problem: symmetry

  Martin Kacer, Oct 2002
}

Program Symetry;

Const MAXPTS = 100000;

Type
	TPoint = Record X, Y: Integer; End;

Var Pts : Array [1..MAXPTS] of TPoint;
	NumPts : Integer;


{compare two points - we have to sort them for faster searching;
return true iff (A <= B)}
Function Compare (A, B: TPoint) : Boolean;
Begin
	If (A.X < B.X) then Compare := True
	else If (A.X > B.X) then Compare := False
	else Compare := (A.Y <= B.Y);
End;

Function Middle (A, B, C: TPoint) : TPoint;
Begin
	If Compare (A, B) and Compare (B, C) then Middle := B
	else If Compare (C, B) and Compare (B, A) then Middle := B
	else If Compare (A, C) and Compare (C, B) then Middle := C
	else If Compare (B, C) and Compare (C, A) then Middle := C
	else Middle := A;
End; { Middle }

{sorting function - not the best implementation but should be ok for us}
Procedure QuickSort (L, R: Integer);
Var LX, RX: Integer;
	Med, X: TPoint;
Begin
	LX := L; RX := R;
	If (L < R) then
	Begin
		Med := Pts[(L+R) div 2];
		If not Compare (Med, Pts[R]) then Med := Pts[R];
		If (R-L > 15) then
			Med := Middle (Pts[L+3], Pts[R-3], Pts[(L+R) div 2 + 2]);
		While (L < R) do
		Begin
			While (L < R) and Compare (Pts[L], Med) do Inc (L);
			While (L < R) and not Compare (Pts[R], Med) do Dec (R);
			If (L < R) then
			Begin
				X := Pts[L]; Pts[L] := Pts[R]; Pts[R] := X;
			End;
		End;
		if Compare (Pts[L], Med) and (L < RX) then
			Inc (L)
		else
			Dec (R);
		QuickSort (LX, R);
		QuickSort (L, RX);
	End;
End;


{find the specified point in a sorted array;
return its index or 0 if not found}
Function BinSearch (X: TPoint) : Integer;
Var L, R, I: Integer;
Begin
	L := 1; R := NumPts;
	While (L < R) do
	Begin
		I := (L+R) div 2;
		If Compare (X, Pts[I]) then R := I else L := I+1;
	End;
	If (X.X = Pts[L].X) and (X.Y = Pts[L].Y)
		then BinSearch := L else BinSearch := 0;
End;


{solve one situation - find the "center of gravity" and check
whether every point has its counterpart}
Function Solve (Var TwiceX, TwiceY: Integer) : Boolean;
Var SX, SY: Integer;
	I: Integer;
	X: TPoint;
Begin
	Solve := false;
	QuickSort (1, NumPts);
	SX := 0; SY := 0;
	For I := 1 to NumPts do
	Begin
		SX := SX + Pts[I].X;
		SY := SY + Pts[I].Y;
	End;
	If ((SX*2) mod NumPts = 0) and ((SY*2) mod NumPts = 0) then
	Begin
		SX := (SX*2) div NumPts;
		SY := (SY*2) div NumPts;
		Solve := true;
		For I := 1 to NumPts do
		Begin
			X := Pts[I];
			X.X := SX - X.X;
			X.Y := SY - X.Y;
			If (BinSearch (X) = 0) then Solve := false;
		End;
	End;
	TwiceX := SX;
	TwiceY := SY;
End;


Var I: Integer;
	X, Y: Integer;

Begin
	Repeat
		ReadLn (NumPts);
		If (NumPts > 0) then
		Begin
			For I := 1 to NumPts do
				ReadLn (Pts[I].X, Pts[I].Y);
			If Solve (X, Y) then
				WriteLn ('V.I.P. should stay at (', X div 2, '.', (X mod 2) * 5,
						',', Y div 2, '.', (Y mod 2) * 5, ').')
			else
				WriteLn ('This is a dangerous situation!');
		End;
	until (NumPts = 0);
End.

