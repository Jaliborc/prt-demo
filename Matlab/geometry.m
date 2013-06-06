function [poses, faces, coords] = geometry(path)
%Assembles the geometry from a set of obj files into a matrix.
    files = openFiles(path);
    poses = [];
    
    for i = 1:size(files)
        pose = scanFile(files(i), 'v %f %f %f');
        poses = [poses pose];
    end
    
    frewind(files(1));
    faces = scanFile(files(1), 'f %d%*s %d%*s %d%*s') - 1;
    
    frewind(files(1));
    data = scanFile(files(1), 'f %d/%d %d/%d %d/%d');
    coords = data(2:2:end) - 1;
    
    closeFiles(files);
end

