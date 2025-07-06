fInput = fopen( "Int32_tAddInput.bin", "wb" );
fExp = fopen( "Int32_tAddExpect.bin", "wb" );

x = randi([-100, 100], 1, 50);  % 50 numeri interi casuali tra -100 e 100
fwrite( fInput, x, "int32");

y = randi([-100, 100], 1, 50);  % 50 numeri interi casuali tra -100 e 100
fwrite( fInput, y, "int32");

SumRes = x + y
fwrite( fExp, SumRes, "int32");

x = randi([-100, 100], 1, 50);  % 50 numeri interi casuali tra -100 e 100
fwrite( fInput, x, "int32");

y = randi([-100, 100], 1, 50);  % 50 numeri interi casuali tra -100 e 100
fwrite( fInput, y, "int32");

SumRes = x + y
fwrite( fExp, SumRes, "int32");

x = randi([-100, 100], 1, 50);  % 50 numeri interi casuali tra -100 e 100
fwrite( fInput, x, "int32");

y = randi([-100, 100], 1, 50);  % 50 numeri interi casuali tra -100 e 100
fwrite( fInput, y, "int32");

SumRes = x + y
fwrite( fExp, SumRes, "int32");

x = randi([-100, 100], 1, 50);  % 50 numeri interi casuali tra -100 e 100
fwrite( fInput, x, "int32");

y = randi([-100, 100], 1, 50);  % 50 numeri interi casuali tra -100 e 100
fwrite( fInput, y, "int32");

SumRes = x + y
fwrite( fExp, SumRes, "int32");

fclose(fInput);
fclose(fExp);
