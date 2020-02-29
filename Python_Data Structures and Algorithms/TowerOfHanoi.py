def TowerOfHanoi(n,from_rod,aux_rod,to_rod):
    if n==1:
        print('Move Tile '+str(n)+' from rod '+from_rod +' to rod '+ to_rod)
        return
    TowerOfHanoi(n-1,from_rod,to_rod,aux_rod)
    print('Move Tile '+str(n)+' from rod '+from_rod +' to rod '+ to_rod)
    TowerOfHanoi(n-1,aux_rod,from_rod,to_rod)


number_of_tiles = 3
TowerOfHanoi(number_of_tiles,'A','B','C')