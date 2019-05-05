program main(input, output);
var p: integer;
var y : integer;
procedure boo(x : integer; y : integer);
	var z : integer;
	procedure foo(x : integer);
		begin
			p := x + 10
		end;
	begin
		write(p);
		z := 10;
		foo(z);
		p := p + z
	end;
begin
	p := 10;
	boo(10,2)
end.
