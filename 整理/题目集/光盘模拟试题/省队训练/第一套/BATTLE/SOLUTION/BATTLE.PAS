{
  CTU Open Contest 2002
  =====================
  Sample solution for the problem: battle

  Martin Kacer, Oct 2002
}

Program Battle;

Const
	MAXSIZE = 10000;
	chShip = '#';
	chWater = '.';

Type TRow = Array [0..MAXSIZE+1] of Char;

Var Row1, Row2 : TRow;
	SizeX, SizeY : Integer;
	IsValid : Boolean;
	ShipCnt : Integer;


{compare two successive rows}
Procedure CompareRows;
Var I: Integer;
Begin
	I := 1;
	While (I <= SizeY) do
	Begin
		If (Row1[I] <> Row2[I]) then
		Begin
			If (Row1[I-1] = chShip) or (Row2[I-1] = chShip) then
				IsValid := false;
			If (Row1[I] = chShip) then
			Begin
				Repeat
					Inc (I);
					If (Row2[I] = chShip) then IsValid := false;
				until (Row1[I] <> chShip)
			End else Begin
				Inc (ShipCnt);
				Repeat
					Inc (I);
					If (Row1[I] = chShip) then IsValid := false;
				until (Row2[I] <> chShip);
			End;
		End;
		Inc (I);
	End;
End;


{read the whole field and compare every two rows}
Procedure ReadAll;
Var X, Y: Integer;
Begin
	For Y := 0 to SizeY+1 do Row1[Y] := chWater;
	Row2[0] := chWater;
	Row2[SizeY+1] := chWater;
	For X := 1 to SizeX do
	Begin
		For Y := 1 to SizeY do
			Read (Row2[Y]);
		ReadLn;
		CompareRows;
		Row1 := Row2;
	End;
End;


Begin
	Repeat
		ReadLn (SizeX, SizeY);
		If (SizeX > 0) then
		Begin
			ShipCnt := 0;
			IsValid := true;
			ReadAll;
			If IsValid then
				WriteLn ('There are ', ShipCnt, ' ships.')
			else
				WriteLn ('Bad placement.');
		End;
	until (SizeX = 0);
End.

