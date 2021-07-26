# Erdős–Rényi model - Random graph's
This repo contains an implementation to Erdős–Rényi model to test it out as a class assignment.<br/>
### c++<br/>

## Main Purpose
We will use graphs with 1000 nodes and check the graph's characteristics :<br/>
1.connectivity<br/>
2.diameter<br/>
3.isolated vertex <br/>
<br/>

- Write a function to build a random graph with a given connectivity probability - p (0-1)<br/>
- Using a adjacency list to represent the graph<br/>
- Impelment functions for each characteristic <br/>
- Impelment bfs algorithm to find the diameter <br/>
- Run on 500 Graph's with different connectivity chances and look for conclusions.<br/>

## Thershold
- To check connectivity we'll define Threshold = lnv(v)/v if the threshold is less than p - the graph should be connected.<br/>
- To check diameter we'll define Threshold = sqrt(2lnv(v)/v) if the threshold is less than p - the graph's diameter should be 2.<br/>
- To check isolated vertex we'll define Threshold = lnv(v)/v if the threshold is less than p - the graph should not have a isolated vertex .<br/>


