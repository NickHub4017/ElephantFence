/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package elephantfence;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author NRV
 */
public class DBLink {
Connection c = null;
    Statement stmt = null;
    
    public DBLink() {
         
    try {
      Class.forName("org.sqlite.JDBC");
      c = DriverManager.getConnection("jdbc:sqlite:test.db");
      System.out.println("Opened database successfully");

      stmt = c.createStatement();
      String sql = "CREATE TABLE nodes " +
                   "(nodeid INT PRIMARY KEY     NOT NULL," +
                   " lat           float    NOT NULL, " + 
                   " lon            float     NOT NULL, " + 
                   " lastping        VARCHAR(20), " + 
                   " lastreply         VARCHAR(20))"; 
      stmt.executeUpdate(sql);
      stmt.close();
      addNode();
    //  c.close();
    } catch ( Exception e ) {
      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
      //System.exit(0);
    
    }
    System.out.println("Table created successfully");
    }
    

    public ArrayList getAllNodes(){
        ArrayList<Node> no_ls;
    try {
        stmt = c.createStatement();
        ResultSet rs = stmt.executeQuery( "SELECT * FROM nodes;" );
        no_ls=new ArrayList<Node>();
      while ( rs.next() ) {
         int id = rs.getInt("nodeid");
         float  lat = rs.getFloat("lat");
         float lon  = rs.getFloat("lon");
         String  lastping = rs.getString("lastping");
         String lastreply = rs.getString("lastreply");
         Node p=new Node(id,lat,lon,lastping,lastreply);
         no_ls.add(p);
      }
      rs.close();
      stmt.close();
      
    } catch (SQLException ex) {
        Logger.getLogger(DBLink.class.getName()).log(Level.SEVERE, null, ex);
        return null;
    }
      return no_ls;
    }
    
    public void addNode(){
    try {
        stmt = c.createStatement();
        String sql = "INSERT INTO nodes  " +
                "VALUES (4,1.1, 2.2, 2015-1-02, 2015-1-02 );";
        stmt.executeUpdate(sql);
        sql = "INSERT INTO nodes  " +
                "VALUES (5,1.1, 2.2, 2015-1-02, 2015-1-02 );";
        stmt.executeUpdate(sql);
        sql = "INSERT INTO nodes  " +
                "VALUES (6,1.1, 2.2, 2015-1-02, 2015-1-02 );";
        stmt.executeUpdate(sql);
        
        
        
        stmt.close();
        c.commit();
    } catch (SQLException ex) {
        Logger.getLogger(DBLink.class.getName()).log(Level.SEVERE, null, ex);
    }
      
    }
    
    
    
}
