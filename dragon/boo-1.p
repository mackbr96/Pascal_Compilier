program main(input, output);
var p: integer;
var y : integer;

var j : integer;
procedure boo(x : integer; y : integer);
	var z : integer;
procedure foo(x : integer);
		begin
			write(p);
			p := p + x
		end;
	begin
		if( x > 10) then
			boo(x-1, 5)
		else
			foo(10)
	end;
function gloo(x : integer) : integer;
	begin
		gloo := p + x
	end;
begin
	p := 10;
	boo(80,2);
	write(p);
	y := gloo(p);
	write(y)
end.
