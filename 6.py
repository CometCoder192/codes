def alphabeta(node, depth, isMax, alpha, beta, tree):
    if depth == 0:
        return tree[node]

    if isMax:
        val = -999
        for i in range(2):
            val = max(val, alphabeta(node*2+i, depth-1, False, alpha, beta, tree))
            alpha = max(alpha, val)
            if alpha >= beta:
                break
        return val
        
    else:
        val = 999
        for i in range(2):
            val = min(val, alphabeta(node*2+i, depth-1, True, alpha, beta, tree))
            beta = min(beta, val)
            if alpha >= beta:
                break
        return val


tree = [3,5,6,9,1,2,0,-1]  # leaf values
print(alphabeta(0, 3, True, -999, 999, tree))