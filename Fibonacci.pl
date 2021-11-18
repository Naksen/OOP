% Recursion:

fibRec(0,0).
fibRec(1,1).
fibRec(N,R):- N1 is N-1, N2 is N-2, 
    fibRec(N1, R1), 
    fibRec(N2, R2), 
    R is R1+R2.

% Call example: 
% ?-fibRec(20,R),write(R).
% 6765

% Tail Recursion:
sub(0, N, _, N).
sub(N, FirstPrevious, SecondPrevious, R):-
    N>0, 
    CurPrev is FirstPrevious+SecondPrevious,
    N1 is N-1,
	sub(N1, SecondPrevious, CurPrev, R).
fibTR(0, 0).
fibTR(1, 1).
fibTR(N, R):- sub(N, 0, 1, R).

% Call example: 
% ?-fibTR(10,R),write(R).
% 55

% Corecursion - couldn't do