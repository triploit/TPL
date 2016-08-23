**TPL - Triploit Programming Language**
===================================

TPL ist die weitentwickelste Programmiersprache von all den Interpretern bisher. Obwohl sie den Titel "Programming Language" enthält, ist sie nicht wirklich eine Programmier, sondern eher eine Skriptsprache.
Sie ähnelt einem Assemblerdialekt, hat jedoch nicht wirklich viel mit Assembler gemeinsam.

Kapitel dieser Readme:
> 	Hallo Welt
>      Mov & Speicher
> 	Includes
>      Do-Anweisung
> 	Input vom User
> 	Run-Anweisung und Punkte
> 	If-Anweisung

###**Hallo Welt**

Ein Hallo Welt Programm würde bestenfalls so aussehen:

    [use] out;

    {main}
      mov "Hallo$Welt",~sa
      do out,~sa
      do out,endline
      end;

Dieses Programm bindet "out" ein und deklariert der Punkt "main". Danach verschiebt man den String "Hallo$Welt" in die Variable ~sa die vom Typ string ist. Wenn dies abgeschlossen ist wird out aufgerufen, welches die Variable ~sa ausgibt. Nach dem wird eine neue Zeile ausgegeben.

"end" beendet das Programm.

###**Mov und Speicher**

####**Speicher**
Es gibt 2 Verschiedene Speichertypen, die je 4 Mitglieder besitzen:

> Der Integer, mit:
> +ia
> +ib
> +id
> +ie
> und der String mit:
> ~sa
> ~sb
> ~sd
> ~se

In jeder dieser Zellen können Verschiedene Werte gespeichert werden, in den Mitgliedern/Zellen mit einem "+i" am Anfang können Zahlen mit der größe eines normalen Integers gespeichert werden, die Zellen die mit "~s" beginnen können Strings speichern.

####**Mov**

Um nun Werte in diese Zellen zu speichern, benötigt man die Funktion "mov":

    mov wert,zelle   

oder

    mov zelle,zelle

Es ist also möglich, Zellen in Zellen zu verschieben. Das ist in manchen Fällen sehr hilfreich. Hier ein  kleines Beispiel zum String:

    mov "Hallo$Welt",~sa
Dies würde den String "Hallo Welt" in die Zelle ~sa verschieben. Das "$" steht dabei für ein Leerzeichen, da ein Leerzeichen so in einem String nicht verwendet werden darf.

Und so sieht das dann aus, wenn ich den Wert 142 in die Zelle +ia verschieben will:

    mov 142,+ia

Natürlich können in jedem Beispiel auch andere Zellen verwendet werden. Man muss nicht immer nur +ia und ~sa verwenden, sondern könnte auch ~se und +ib verwenden. Das ist letzendlich dem Programmierer überlassen, man muss nur daraf achten das man weiß wo der Wert sich dann zum Schluss befindet.

####**Add**

Der Befehl add ist eigentlich komplett das Gleiche wie Mov, nur das Add einen Wert **hinzufügt** und nicht zuerst die Zelle **löscht und dann ihren Wert setzt, wie Mov es tut**.

Beispiel:

    add 1,+ia
Wenn die Zelle +ia den Wert 142 beinhalten würde, wäre es jetzt 143. Bei Strings ist das etwas anders:

    add "!",~sa
Hier wird einfach ein "!" an das Ende, dem Wert, der Zelle ~sa angehängt. Wäre der Wert "Hallo Welt" in der Zelle ~sa, wäre es jetzt "Hallo Welt!" (also ein "!" am Ende mehr).

###**Includes**

Die Funktion out ist nicht von Anfang an eingebunde, sie wird erst mit dem benutzen von

    [use] out;
am Anfang der Datei nutzbar gemacht. Wenn dies nicht passiert, wird der Interpreter out nicht erkennen.

####**Weitere Includes**
Es gibt noch eine weitere Funktion die inkludiert werden kann:

    [use] in;
Damit wird die Funktion "in" eingebunden und kann genutzt werden.

### **Do-Anweisung**

Die Do-Anweisung ist dazu da um verschiedene Sachen zu erledigen, was "do" (Englisch für "tue" oder "mach") schon andeutet. Wir nutzen es so:

    do funktion,zelle;
Das bewirkt das die Funfkion "funktion" mit dem Argument "zelle" ausgeführt wird. Wenn wir nun eine Zelle ausgeben wollen, tun wir dies so:

    do out,~sa
Danach wird Zelle ~sa ausgegeben. Es muss jedoch darafu geachtet werden, das Out eingebunden wurde! Siehe dazu **Includes**.

Hier kann statt Zelle ~sa, auch wieder jede andere beliebige Zelle genommen werden. Das ist überall so. Genauso kann man hier auch Zellen vom Typ Integer (+ia, +ib, +id oder +ie) verwenden.

###**Input vom User**

Um Input entgegenzunehmen, müssen wir die Funktion IN einbinden. Siehe dazu **Includes**.
Wenn wir nun einen String entgegennehmen und diesen beispielsweise in die Zelle ~sd schreiben, machen wir dies:

    do in,~sd
Dann wird die Funktion Input ausgeführt und Speichert den Wert in die Zelle ~sd. Bei Integern sieht das so aus:

    do in,+ie
Das bedeutet, dass hier eine Zahl entgegengenommen wird und dann wird die Eingabe in die Zelle +ie gespeichert.

###**Run Anweisung und Punkte**

####**Punkte**
Einen Punkt haben wir schon im Hello-World Beispiel gesehen. Den {main} Punk. Punkte werden so deklariert:

    {Name}
Dann hätten wir den Punk "Name" erstellt.

####**Run**

Um nun von jeder Stelle des Programmes aus zu einem Punk zu springen, nutzen wir dies:

    run Name;
Dann würde der Interpreter zu dem Punk "Name" Springen und von da an den Code ausführen. So sind auch scheleifen möglich.

Wenn eine deklaration doppelt vorkommt, wird der nächst "höhere" Punkt angesprochen:

    {Name}
      run Punkt;

    {Name}
      mov "Hi!",~sa;
      do out,~sa;
      do out,endline;
      end;

    {Punkt}
      run Name;
Nachdem "run Punkt;" ausgeführt wird und der Interpreter zu "Punkt" gesprungen ist, wird die zweite, untere deklaration von "Name" ausgeführt, da sieh am nächsten über "Punkt" deklariert wurde.

###**If Anweisung**

Die If-Anweisung müsste jeder Programmierer kennen. Hier ist sie etwas anders:

    eq zelle1=zelle2,punkt;

Überprüft ob der Wert von Zelle1, dem Wert von Zelle2 entspricht, wenn dies der Fall ist, springt der Interpreter zu dem Punkt "punkt".

    eq zelle1!zelle2,punkt;

Überprüft ob der Wert von Zelle1, **nicht** dem von Zelle2 entspricht, wenn dies der Fall ist, springt der Interpreter zu dem Punkt "punkt".

**Der Unterschied dabei ist:** zwischen den Zellen steht entweder ein "=" oder ein "!". Das "!" steht für ungleichheit, das "=" für gleichheit.

Beispiel Integer:

    {main}
      mov 2,+ia;
      add 1,+ib;
      eq +ia!+ib,main;
Das bewirkt, dass der Interpreter prüft, ob +ia und +ib nicht gleich sind. Solange das zutrifft geht er zu main. Da in main aber ein "add 1,+ib;" steht und kein "mov 1,+ib;", bleibt der Wert von +ib beim Sprung erhalten und wird erhöht. Am Ende des Programms, wenn +ia und +ib den gleichen Wert haben, kann man dies ausgeben um das Ergebnis zu überprüfen.

Beim String ist es das gleiche, es gibt keinen Unterschied:

    {main}
      mov "11",~sa;
      add "1",~sb;
      eq ~sa!~sb,main;

###**Anmerkungen**

Am Ende eines Befehls müssen keine Semikolons stehen, sieht aber besser aus und empfehle ich jedem. Die Formatierung sollte auch beachtet werden um die lesbarkeit des Quellcodes zu steigern.

>**Wichtig:** Achtet auf die groß und kleinschreibung bei den Punkten, Werten, Funktionen und Zellen! Also eigentlich überall.

Wenn ihr noch Fragen habt oder irgendwelche Vorschläge, was ich noch hinzufügen kann. Schreibt mir eine Nachricht auf: http://triploit.bitbucket.org/contact.html oder an die E-Mail "tristanpieper080803@gmail.com".