# -*- coding: utf-8 -*-
"""
Created on Tue Mar 31 19:39:15 2020

@author: shubham
"""
import matplotlib.pyplot as plt#lib for showing graph
 
class AStar(object):
 
	def __init__(self):
		self.barriers = []
        #here we can add coordinates of the barriers
		self.barriers.append([(2,5),(2,6),(3,6),(4,6),(5,6),(5,5),(5,4),(5,3),(5,2),(4,2),(3,2),(2,2)])
	def heuristic(self, start, goal):
		#Using Chebyshev distance heuristic i.e. maximum of |x2-x1| or |y2-y1|
		dx = abs(start[0] - goal[0])#abs() is for modulus
		dy = abs(start[1] - goal[1])
		return max(dx, dy)
 
	def neighbours(self, pos):
		n = []
		#nieghbours include the coordinates all 8 adjacent an daigonal points
		for dx, dy in [(1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,1),(1,-1),(-1,-1)]:
			x2 = pos[0] + dx
			y2 = pos[1] + dy
			if x2 < 0 or x2 > 7 or y2 < 0 or y2 > 7:#for boundary points
				continue#       we can CHANGE these to increase the size of mapping area
			n.append((x2, y2))# adding them as nieghbours
		return n
 
	def move_cost(self, a, b):
		for barrier in self.barriers:
			if b in barrier:
				return 100 # comparatively high cost to enter barrier squares
		return 1 #Normal movement cost
 
def AStarSearch(start, end, graph):
 
	G = {} #Actual movement cost to each point from the starting point
	F = {} #Estimated movement cost of start to end going via this position
 
	#Initialize starting values
	G[start] = 0 
	F[start] = graph.heuristic(start, end)# F = G + heuristic (at start G=0)
 
	closedVertices = set()
	openVertices = set([start])
	cameFrom = {}
 
	while len(openVertices) > 0:
		#Get the vertex in the open list with the lowest F score
		current = None
		currentFvalue = None
		for pos in openVertices:
			if current is None or F[pos] < currentFvalue:
				currentFvalue = F[pos]
				current = pos
 
		#Check if we have reached the goal
		if current == end:
			#Retrace our route backward
			path = [current]
			while current in cameFrom:
				current = cameFrom[current]#storing the vertices of the path 
				path.append(current)
			path.reverse()
			return path, F[end] # done
 
		#Mark the current point as closed
		openVertices.remove(current)
		closedVertices.add(current)
 
		#Update scores for vertices near the current position
		for neighbour in graph.neighbours(current):
			if neighbour in closedVertices: 
				continue #We have visited this point.
			newG = G[current] + graph.move_cost(current, neighbour)
 
			if neighbour not in openVertices:
				openVertices.add(neighbour) #discovered a new vertex
			elif newG >= G[neighbour]:
				continue #This G score is worse than previously found
 
			#adopting this G value
			cameFrom[neighbour] = current
			G[neighbour] = newG
			H = graph.heuristic(neighbour, end)
			F[neighbour] = G[neighbour] + H
 
	raise RuntimeError("A* failed to find a solution")
 
if __name__=="__main__":#The main function
	graph = AStar()
	result, cost = AStarSearch((4,4), (7,5), graph)#here we can CHANGE the initial and final points.
	print ("path", result)
	print ("cost", cost)
	plt.plot([v[0] for v in result], [v[1] for v in result])#printing path
	for barrier in graph.barriers:
		plt.plot([v[0] for v in barrier], [v[1] for v in barrier])#printing barrier
	plt.xlim(-1,8)
	plt.ylim(-1,8)#here we can CHANGE the dimensions of graph.
	plt.show()