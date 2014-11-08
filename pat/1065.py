Tc = (int)(raw_input());
for i in range(0, Tc):
    res = raw_input().split(' ');
    a = (int)(res[0]);
    b = (int)(res[1]);
    c = (int)(res[2]);
    if a + b > c:
        print 'Case #{0}: true'.format(i + 1)
    else:
        print 'Case #{0}: false'.format(i + 1)
