%U = csvread('../testfile.csv');

% if using a 16x16 grid: 17 is the magic number
magic = 17;

full = csvread('../testfile.csv');
size_u = size(full); 
U = zeros(magic, size_u(2)-1, floor(size_u(1)/magic));

% initial value
U(:,:,1) = csvread('../testfile.csv', 0, 0, [0,0,magic-1,magic]);

for i = 1:floor(length(U)/magic)

    U(:,:,i+1) = csvread('../testfile.csv', i*magic, 0, [i*magic, 0, (i+1)*magic-1, magic]);
    
end

% x*it*magic+1, 0, [x*it*magic, 0, x*(it+1)*magic+1, magic]