program ex2;
var i:integer;
    a:array[1..10] of integer;
begin
for i:= 1 to 10 do
    a[i] := i * i div 2;
for i:= 10 downto 1 do
    writeln(a[i]);
end.
