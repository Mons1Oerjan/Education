JFLAGS = -g
JC = javac
JVM = java
FILE =

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	main.java \
	HashMap.java \
	HashEntry.java \
	DeletedEntry.java \

MAIN = main

default: classes

classes: $(CLASSES:.java=.class)

run: $(MAIN).class
	$(JVM) $(MAIN)

clean:
	$(RM) *.class
