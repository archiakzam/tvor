#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <string>

using namespace std;

void draw_circle(double x, double y, double radius) { 
    const int num_segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.7f, 0.7f, 0.7f); 
    glVertex2d(x, y); 
    for (int i = 0; i <= num_segments; ++i) {
        double angle = 2.0 * 3.1415 * i / num_segments;
        double dx = radius * cos(angle);
        double dy = radius * sin(angle);
        glColor3f(0.0f, 0.0f, 0.0f); 
        glVertex2d(x + dx, y + dy);
    }
    glEnd();
}
void draw_line(double x1, double y1, double x2, double y2) {  
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();
}
void draw_text(double x, double y, const string& text, int size) {  
    glColor3f(0.0f, 0.0f, 0.0f); 
    glRasterPos2d(x, y);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c); 
    }
}

class GraphClass {
private:
    vector<int> vertex_list;
    vector<vector<int>> adjacency_matrix;
    int max_size;
    int vertex_count;

public:
    GraphClass(int size) : max_size(size), vertex_count(0) {
        adjacency_matrix = vector<vector<int>>(size, vector<int>(size, 0));
    }
    bool is_full() {
        return vertex_count == max_size;
    }
    bool is_empty() {
        return vertex_count == 0;
    }
    void insert_vertex(int vertex) {
        if (!is_full()) {
            cout << "\"+\" ������� " << vertex << " ���������!\n";
            vertex_list.push_back(vertex);
            vertex_count++;
        }
        else {
            cout << "���������� �������� �������: ���������� ������������ ���������� ������\n";
        }
    }
    void delete_vertex(int vertex) {
        if (!is_empty()) {
            cout << "\"-\" ������� " << vertex << " �������!\n";
            vertex_list.pop_back();
            vertex_count--;
        }
        else {
            cout << "���������� ������� �������: ���� ����\n";
        }
    }
    int get_vertex_position(int vertex) {
        for (int i = 0; i < vertex_count; i++) {
            if (vertex_list[i] == vertex) {
                return i;
            }
        }
        return -1;
    }
    int get_amount_vertex() {
        return vertex_count;
    }
    int get_weight(int v1, int v2) {
        int v1_pos = get_vertex_position(v1);
        int v2_pos = get_vertex_position(v2);
        if (v1_pos == -1 || v2_pos == -1) {
            cout << "����� �� ����� � ����� �� ����������\n";
            return 0;
        }
        return adjacency_matrix[v1_pos][v2_pos];
    }
    vector<int> get_neighbours(int vertex) {
        vector<int> neighbours_list;
        int pos = get_vertex_position(vertex);
        if (pos != -1) {
            for (int i = 0; i < vertex_count; ++i) {
                if (adjacency_matrix[pos][i] != 0) {
                    neighbours_list.push_back(vertex_list[i]);
                }
            }
        }
        return neighbours_list;
    }
    void insert_edge(int vertex_1, int vertex_2, int weight = 1) {
        int vertex_pos_1 = get_vertex_position(vertex_1);
        int vertex_pos_2 = get_vertex_position(vertex_2);

        if (vertex_pos_1 == -1 || vertex_pos_2 == -1) {
            cout << "����� �� ������ � ����� �� ����������\n";
            return;
        }

        if (adjacency_matrix[vertex_pos_1][vertex_pos_2] == 0 && adjacency_matrix[vertex_pos_2][vertex_pos_1] == 0) {
            adjacency_matrix[vertex_pos_1][vertex_pos_2] = weight;
            adjacency_matrix[vertex_pos_2][vertex_pos_1] = weight;
            std::cout << "\"+\" ����� �� ������� " << vertex_1 << " � ������� " << vertex_2 << " ���������!\n";
        }
        else {
            cout << "����� ����� ��������� ��� ����\n";
        }
    }
    void delete_edge(int vertex_1, int vertex_2) {
        int pos_1 = get_vertex_position(vertex_1);
        int pos_2 = get_vertex_position(vertex_2);

        if (pos_1 == -1 || pos_2 == -1) {
            cout << "����� �� ������ � ����� �� ����������\n";
            return;
        }

        if (adjacency_matrix[pos_1][pos_2] == 0 || adjacency_matrix[pos_2][pos_1] == 0) {
            cout << "����� ����� ��������� �����������\n";
        }
        else {
            adjacency_matrix[pos_1][pos_2] = 0;
            adjacency_matrix[pos_2][pos_1] = 0;
            cout << "����� ����� ��������� " << vertex_1 << " � " << vertex_2 << " �������\n";
        }
    }
    void print() {
        if (!is_empty()) {
            cout << "������� ��������� �����:\n";

            cout << "   ";
            for (int i = 0; i < vertex_count; i++) {
                cout << " " << vertex_list[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < vertex_count; i++) {
                cout << " " << vertex_list[i] << " ";
                for (int j = 0; j < vertex_count; j++) {
                    cout << " " << adjacency_matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "���� ����\n";
        }
    }
    int get_amount_edges() {
        int amount = 0;
        for (int i = 0; i < vertex_count; i++) {
            for (int j = i; j < vertex_count; j++) {
                if (adjacency_matrix[i][j] != 0) {
                    amount++;
                }
            }
        }
        return amount;
    }
    void DFS(int start_vertex, bool* visited_vertex) {
        cout << "������� " << start_vertex << " ��������\n";
        visited_vertex[get_vertex_position(start_vertex)] = true;
        vector<int> neighbours = get_neighbours(start_vertex);
        for (int i = 0; i < neighbours.size(); i++) {
            if (!visited_vertex[get_vertex_position(neighbours[i])]) {
                DFS(neighbours[i], visited_vertex);
            }
        }
    }
    void BFS(int start_vertex, bool* visited_vertex) {
        queue<int> queue;
        visited_vertex[get_vertex_position(start_vertex)] = true;
        queue.push(start_vertex);

        while (!queue.empty()) {
            int current_vertex = queue.front();
            queue.pop();
            cout << "������� " << current_vertex << " ��������\n";

            vector<int> neighbours = get_neighbours(current_vertex);
            for (int i = 0; i < neighbours.size(); i++) {
                int neighbour_vertex = neighbours[i];
                int neighbour_pos = get_vertex_position(neighbour_vertex);
                if (!visited_vertex[neighbour_pos]) {
                    visited_vertex[neighbour_pos] = true;
                    queue.push(neighbour_vertex);
                }
            }
        }
    }
    int shortest_path(int start_vertex, int end_vertex) {
        vector<int> distance(vertex_count, numeric_limits<int>::max());
        distance[get_vertex_position(start_vertex)] = 0;

        vector<int> previous(vertex_count, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, start_vertex });

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            vector<int> neighbours = get_neighbours(u);
            for (int i = 0; i < neighbours.size(); i++) {
                int v = neighbours[i];
                int weight = get_weight(u, v);
                if (distance[get_vertex_position(v)] > distance[get_vertex_position(u)] + weight) {
                    distance[get_vertex_position(v)] = distance[get_vertex_position(u)] + weight;
                    previous[get_vertex_position(v)] = u;
                    pq.push({ distance[get_vertex_position(v)], v });
                }
            }
        }

        cout << "���������� ���� �� " << start_vertex << " � " << end_vertex << " �������� ����� ��������� ������� ";
        stack<int> path;
        int current_vertex = end_vertex;
        while (current_vertex != -1) {
            path.push(current_vertex);
            current_vertex = previous[get_vertex_position(current_vertex)];
        }
        while (!path.empty()) {
            if (path.size() == 1) {
                cout << path.top();
            }
            else {
                cout << path.top() << "->";
            }
            path.pop();
        }
        cout << " � ����� " << distance[get_vertex_position(end_vertex)];
        cout << endl;

        return distance[get_vertex_position(end_vertex)];
    }
    void draw_graph() const {

        double angle = 2 * 3.1415 / vertex_count; 

        // Draw vertices
        double min_dimension = min(800.0, 600.0); 
        double radius = min_dimension / 3; 
        for (int i = 0; i < vertex_count; ++i) {
            double x = 400 + radius * cos(i * angle);
            double y = 300 + radius * sin(i * angle);
            draw_circle(x, y, 30); 
            draw_text(x - 5, y + 5, to_string(vertex_list[i]), 16); 
        }

        // Draw edges
        for (int i = 0; i < vertex_count; ++i) {
            for (int j = i + 1; j < vertex_count; ++j) {
                if (adjacency_matrix[i][j] != 0) {
                    double mid_x = (400 + radius * cos(i * angle) + 400 + radius * cos(j * angle)) / 2;
                    double mid_y = (300 + radius * sin(i * angle) + 300 + radius * sin(j * angle)) / 2;
                    draw_line(400 + radius * cos(i * angle), 300 + radius * sin(i * angle),
                        400 + radius * cos(j * angle), 300 + radius * sin(j * angle));
                    // Draw text showing edge weight
                    draw_text(mid_x - 5, mid_y + 5, to_string(adjacency_matrix[i][j]), 12); 
                }
            }
        }
    }
};
