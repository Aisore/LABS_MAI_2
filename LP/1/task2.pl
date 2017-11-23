% Task 2: Relational Data

% The line below imports the data
:- ['one.pl'].

%Вариант 2


average_mark(X, F) :- subject(Z, X), findall(Y, grade(_, Z, Y), A), 
                    sum_list(A, Sm),                 
                    length(A, Ln), 
                    F is Sm / Ln.
loosers_by_sbj(X, F) :- subject(Z, X), findall(Y, grade(Y, Z, 2), A),
                    length(A, F).
                    
delete_all(_,[],[]).
delete_all(X,[X|L],L1):-delete_all(X,L,L1).
delete_all(X,[Y|L],[Y|L1]):- X \= Y, delete_all(X,L,L1).

remove_same([],[]).
remove_same([H|T],[H|T1]):-delete_all(H,T,T2), remove_same(T2,T1).

loosers_by_gr(Z, F) :- findall(X,(student(Z,X), grade(X, _, 2)),A),
	        remove_same(A,New),
                    length(New, F).