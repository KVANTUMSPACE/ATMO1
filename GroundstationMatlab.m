clear all
a = arduino('COM4','Nano');
line1 = line(nan, nan,'color', 'blue');
i = 0;

while 1
    temp1 = readVoltage(a, 'A0')*10;
    pause(0.001);
       
    
    x1= get(line1, 'xData');
    y1= get(line1, 'yData');
    
    x1 = [x1 i];
    y1 = [y1 temp1];
            
    set(line1, 'xData', x1, 'yData', y1);
    
    i=i+1;
    pause(0.001);
end