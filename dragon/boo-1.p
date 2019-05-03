program main(input, output);
var x: integer;
procedure foo(x : integer);
	begin
		x := 10;
		write(x)
	end;
begin
	foo(x);
	x := 6
end.
