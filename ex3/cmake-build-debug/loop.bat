 FOR /L %%A IN (1,1,200) DO (
  ECHO running with the parameter of %%A
  ex3.exe big.txt 100 %%A N N
)
pause