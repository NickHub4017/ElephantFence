/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package threadtest;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author NRV
 */
public class Mythread extends Thread{
int tno=0;
int x=0;

    public Mythread(int p) {
        tno=p;
    }

    @Override
    public void run() {
     for (int j=0;j<15;j++){   
        super.run(); //To change body of generated methods, choose Tools | Templates.
        ThreadTest.printdata("t "+tno+" @ "+(x++));
    try {
        Thread.sleep(1000);
    } catch (InterruptedException ex) {
        Logger.getLogger(Mythread.class.getName()).log(Level.SEVERE, null, ex);
    }
    }
    }
    
}
