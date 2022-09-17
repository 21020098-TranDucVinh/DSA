// Size của thành phần liên thông max trong đồ thị
// Java 

int componentSize(boolean[][] matrix, int vertex) {
    Set<Integer> res = new HashSet<>();
    res.add(vertex);
    addConnection(matrix, vertex, res);
    return res.size();
}

void addConnection(boolean[][] matrix, int vertex, Set<Integer> conn) {
    for (int i = 0; i < matrix.length; i++) {
        if (matrix[vertex][i] && !conn.contains(i)) {
            conn.add(i);
            addConnection(matrix, i, conn);
        }
    }
}