if exist .\src\Birdee\Debug\Birdee.exe (.\src\Birdee\Debug\Birdee.exe -ls .\lib\Exceptions.dkm .\lib\Exceptions.bdl) else (.\src\Birdee\Birdee\Birdee.exe -ls .\lib\Exceptions.dkm .\lib\Exceptions.bdl)
if exist .\src\Birdee\Debug\Birdee.exe (.\src\Birdee\Debug\Birdee.exe -ls .\lib\Remote.dkm .\lib\Remote.bdl) else (.\src\Birdee\Birdee\Birdee.exe -ls .\lib\Remote.dkm .\lib\Remote.bdl)
wmic ENVIRONMENT create name="BDL_LOAD_SEARCH_PATH",username="<system>",VariableValue="%cd%\lib"
wmic ENVIRONMENT where "name='BDL_LOAD_SEARCH_PATH' and username='<system>'" set VariableValue="%cd%\lib"
wmic ENVIRONMENT create name="DKH_LOAD_SEARCH_PATH",username="<system>",VariableValue="%cd%\lib"
wmic ENVIRONMENT where "name='DKH_LOAD_SEARCH_PATH' and username='<system>'" set VariableValue="%cd%\lib"
