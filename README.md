# Campus Navigation System - Data Structure Course Design
**Date:** 2024.2.22

## Overview
This is a simplistic campus navigation system developed as part of a data structure course design project. The system is implemented in C and leverages graph theory, specifically using Floyd's algorithm for shortest path computation.

**Note:** All distances and routes are fictional. Any resemblance to real locations or situations is purely coincidental.

## Features
- **Graph Representation:** The campus is represented as a graph, where buildings or locations are nodes, and paths between them are edges with associated distances.
- **Floyd's Algorithm:** The system employs Floyd's algorithm to calculate the shortest paths between all pairs of nodes, ensuring efficient navigation across the campus.
- **User Interaction:** Users can input start and end locations to get the shortest route between them.

## Technical Details
- **Language:** C
- **Data Structures Used:**
  - **Graph:** Represented using adjacency matrices.
  - **Array:** Used for storing distances and paths.
  - **Input/Output Handling:** Standard C I/O functions for user interaction.
