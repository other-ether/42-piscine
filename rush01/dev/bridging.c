so population.c assumes an empty array but because it accepts any array as a parameter, it could be possible to accept a partially filled array too
if we add an if condition somewhere right before the guessing assignment or the guessloop 
no it has to be inside the while (guess<4) because that's where the recursion happens
OR I HAVE TO PUT IT ABOVE AND JUST DO ANOTHER RECURSION ENTRY POINT
ok and then that means that the bottom line layout[spot]=0 is safe because when a prefilled spot is considered for a loop, it won't even reach that line. 

    if (layout[spot] != 0)
        return (population(spot + 1, layout, params));
