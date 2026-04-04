import backend

graph, source, destinations, ow = backend.build_default_graph()

print(f"Num nodes: {graph.get_number_of_nodes()}")
print(f"Source: {source}, Destinations: {destinations}")

for i in range(graph.get_number_of_nodes()):
    print(f"Node {i}: {graph.get_node_name(i)} | Floor {graph.get_node_floor(i)}")

result = backend.PathFinder.find_shortest_path(graph, source, destinations)
print(f"Shortest path found: {result.found()}")
print(f"Hit destination: {result.destination_node}")
print(f"Distance: {result.distance}")
print(f"Path: {result.path}")

print("Blocking edge (1, 2)..")
# 1 is Hallway A, 2 is Main Exit, so Main Exit is blocked basically
graph.block_corridor(1, 2)
result_blocked = backend.PathFinder.find_shortest_path(graph, source, destinations)
print(f"After block shortest path found: {result_blocked.found()}")
print(f"After block Hit destination: {result_blocked.destination_node}")
print(f"After block Distance: {result_blocked.distance}")
print(f"After block Path: {result_blocked.path}")
