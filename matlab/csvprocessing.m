%% Process CSV files of U, V, and P matrices

magic = 23;

% ufile = '../udata_DC.csv';
% vfile = '../vdata_DC.csv';
% pfile = '../pdata_DC.csv';
% % 
% ufile = '../udata_RE20.csv';
% vfile = '../vdata_RE20.csv';
% pfile = '../pdata_RE20.csv';

ufile = '../udata_RE100.csv';
vfile = '../vdata_RE100.csv';
pfile = '../pdata_RE100.csv';

%% U matrix
full = csvread(ufile);
size_u = size(full); 
steps = floor(size_u(1)/magic);
U = zeros(magic-2, magic-2, steps);

% initial value
U(:,:,1) = csvread(ufile, 1, 1, [1,1,magic-2,magic-2]);

for i = 1:steps
    try     
        U(:,:,i+1) = csvread(ufile, i*magic+1, 1, [i*magic+1, 1, (i+1)*magic-2, magic-2]);
    catch
        break;
    end
end

%% V matrix

full = csvread(vfile);
size_v = size(full); 
steps = floor(size_v(1)/magic);
V = zeros(magic-2, magic-2, steps);

% initial value
V(:,:,1) = csvread(vfile, 1, 1, [1,1,magic-2,magic-2]);

for i = 1:steps
    try
        V(:,:,i+1) = csvread(vfile, (i*magic)+(1+i), 1, [(i*magic)+(1+i), 1, (i+1)*magic-2+i, magic-2]);
    catch
        break;
    end
end

%% P matrix

full = csvread(pfile);
size_p = size(full); 
steps = floor(size_p(1)/magic);
P = zeros(magic-2, magic-2, steps);

% initial value
P(:,:,1) = csvread(pfile, 1, 1, [1,1,magic-2,magic-2]);

for i = 1:steps
    try
        P(:,:,i+1) = csvread(pfile, (i*magic)+(1+i), 1, [(i*magic)+(1+i), 1, (i+1)*magic-2+i, magic-2]);
    catch
        break;
    end
end

%% Plotting

matsize = size(U);
T = matsize(3);

for t=1:T
    
    %u_plot = 0.5*(U(1:magic-3, 2:magic-2, t)+U(1:magic-3, 1:magic-3, t));
    %v_plot = 0.5*(V(2:magic-2, 1:magic-3, t)+V(1:magic-3, 1:magic-3, t));

    %contour_plot = (U(1:magic-3, 2:magic-2, t)-U(1:magic-3, 1:magic-3, t) ...
        %-V(2:magic-2, 1:magic-3, t)+V(1:magic-3, 1:magic-3, t))/(2*(magic-3));

    %subplot(3,1,1)
    %quiver(u_plot',v_plot', 'r')
    %subplot(3,1,2)
    %contour(contour_plot')
    %subplot(3,1,3)
    
    subplot(2,1,1)
    quiver(U(:,:,t)', V(:,:,t)')
    subplot(2,1,2)
    image(sqrt(P(:,:,t).^2), 'CDataMapping', 'scaled')
    pause(0.03);
end

