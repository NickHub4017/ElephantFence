/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package elephantfence;

/**
 *
 * @author NRV
 */
public class Node {
    int nodeid;
    float lat;
    float lon;
    String lastping;
    String lastreply;
   

    public Node(int nodeid, float lat, float lon, String lastping, String lastreply) {
        this.nodeid = nodeid;
        this.lat = lat;
        this.lon = lon;
        this.lastping = lastping;
        this.lastreply = lastreply;
    }
}
