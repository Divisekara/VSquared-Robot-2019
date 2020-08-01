void completeTask()
{
    mainTask = 0;
    while (mainTask == 0)
    {
        lineMaze();
        mainTask +=1;
    }

    while (mainTask == 1)
    {
        Maze_Complete();
    }

    while (mainTask == 2)
    {
        Water_Line_Follow();
    }
    
}