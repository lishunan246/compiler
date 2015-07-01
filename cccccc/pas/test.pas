program ex1;
var x, y, z:integer;

function gcd(a:integer; b:integer):integer;
begin
    if b=0 then
        gcd := a
    else
        gcd := gcd(b, a mod b);
end;

begin
    x := 100;
    y := 80;
    z := gcd(x, y);
    write(z);
end.
