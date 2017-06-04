disp('    Links     Rechts    Degree');
%for i = -pi/2:1/40:pi/2
    x = 0.91;%cos(i);
    y = 0.41;%sin(i);
    links = 0;
    rechts = 0;
    if ( x <= 0 )
        if ( y > 0 ) 
            rechts = hypot(x, y);
            links = x + y;
        elseif ( y < 0)
            links = hypot(x, y);
            rechts = x -y;
        end
    elseif ( x > 0 )
        if ( y > 0 ) 
            links = hypot(x, y);
            rechts = x - y;
        elseif ( y < 0)
            rechts = hypot(x, y);
            links = x + y;
        end
    end
    disp([links rechts]);
    
%end