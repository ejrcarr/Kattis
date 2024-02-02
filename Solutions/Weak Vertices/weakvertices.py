while True:
    x = int(input())
    if x == -1:
        break
    edgesMap = {}
    for rowIndex in range(x):
        rowArray = [int(i) for i in input().split(" ")]
        for index, element in enumerate(rowArray):
            if rowIndex not in edgesMap:
                edgesMap[rowIndex] = set()
            if element == 1:
                edgesMap[rowIndex].add(index)

    weakVertices = []
    for originalVertex in edgesMap.keys():
        isVertexWeak = True
        for firstNeighbor in edgesMap.get(originalVertex):
            for secondNeighbor in edgesMap.get(firstNeighbor):
                if originalVertex in edgesMap.get(secondNeighbor):
                    isVertexWeak = False
                    break
            if not isVertexWeak:
                break
        if isVertexWeak:
            weakVertices.append(str(originalVertex))

    print(" ".join(weakVertices))