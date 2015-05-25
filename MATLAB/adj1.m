adjA=[A(2,2), -A(1,2);-A(2,1), A(1,1)];
detA=A(1,1)*A(2,2)-A(1,2)*A(2,1);
invA=adjA/detA;
disp('detA');
disp(detA);
disp('invA');
disp(invA);