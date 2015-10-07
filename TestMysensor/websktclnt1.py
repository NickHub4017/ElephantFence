#run aria2.exe as follows aria2c --enable-rpc --rpc-listen-all=true --rpc-allow-origin-all
#http://aria2.sourceforge.net/manual/en/html/aria2c.html#json-rpc-over-websocket
#me link eke tiyena event kiyana tika nikmma enawa.
#bt dwn speed wage ewa ganna hello method eka athule thiyena data kiyana json eka wenas krnna oni.
###############################################################################
import RPi.GPIO as GPIO
from time import sleep


from autobahn.twisted.websocket import WebSocketClientProtocol, \
    WebSocketClientFactory
import json
GPIO.setmode(GPIO.BCM)


GPIO.setup (23,GPIO.OUT)
GPIO.setup (24,GPIO.OUT)

class MyClientProtocol(WebSocketClientProtocol):

    def onConnect(self, response):
        print("Server connected: {0}".format(response.peer))

    def onOpen(self):
        print("WebSocket connection open.")
        self.sendMessage("LOGIN #name nirm #skey 12345 @mysensors")
        

    def onMessage(self, payload, isBinary):
        if isBinary:
            print("Binary message received: {0} bytes".format(len(payload)))
        else:
            print("Text message received: {0}".format(payload.decode('utf8')))
            x=format(payload.decode('utf8'))
            y=x.split(" ")
            print y
            if(y[0]=="@Randul" and len(y)==4):
                    if(y[2]=="#u1" and y[3]=="on"):
                            print "on 1"
                            GPIO.output(23,True)
                    if(y[2]=="#u1" and y[3]=="off"):
                            print "off 1"
                            GPIO.output(23,False)
                    if(y[2]=="#u2" and y[3]=="on"):
                            print "on 2"
                            GPIO.output(24,True)
                    if(y[2]=="#u2" and y[3]=="off"):
                            print "off 2"
                            GPIO.output(24,False)

    def onClose(self, wasClean, code, reason):
        print("WebSocket connection closed: {0}".format(reason))


if __name__ == '__main__':

    import sys

    from twisted.python import log
    from twisted.internet import reactor

    log.startLogging(sys.stdout)

    factory = WebSocketClientFactory("ws://connect.mysensors.info:8080", debug=False)
    factory.protocol = MyClientProtocol

    reactor.connectTCP("connect.mysensors.info", 8080, factory)
    reactor.run()
