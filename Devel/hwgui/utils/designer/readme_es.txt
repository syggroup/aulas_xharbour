Dise�ador
~~~~~~~~~

1. Caracter�sticas principales.
2. Los archivos de la carpeta \hwgui\utils\designer
3. Algunas notas para aplicaciones HwGUI

1.  Caracter�sticas principales.

  1.1.El conjunto de controles es completamente configurable.
     La  lista de controles (widgets) se coloca en el archivo
     especial de configuraci�n con formato de XML. El nombre de
     ese  archivo  est� en el archivo ini "Designer.iml"  del
     Dise�ador, actualmente es el resource/widgets.xml.
     Para  agregar  un  control nuevo o a�n  un  conjunto  de
     controles,  o  agregar  los  propiedades/m�todos  nuevos
     para  un  control  es  f�cil ahora  -  edita  apenas  el
     widgets.xml. Esto permite utilizar el Dise�ador no  s�lo
     para   HwGUI   se   bas�,  pero  para  cualquier   otras
     aplicaciones - usted puede crear completamente un  nuevo
     conjunto de controles para sus prop�sitos.

  1.2.El  Dise�ador  puede ser construido  no  s�lo  como  el
     programa aut�nomo, puede ser parte de otra aplicaci�n donde
     se le necesita para editar �forms� en tiempo de ejecuci�n.

  1.3.Los formatos de salida son configurables debido al  uso
     de  �scripts� (escrituras) externos. El apoyo nativo del
     formato de HwGUI se incluye en el c�digo del Dise�ador, todos
     los  otros se incluyen como plugins. Hay actualmente dos
     plugins.
     -     para    leer    los    viejos    archivos     .frm
   (resource/F_text.prg) y para escribir los prgs
     - F_hwgprg. prg (no completamente funcional todav�a).

  1.4.El dise�ador permite describir no s�lo propiedades, los
     m�todos, tambi�n - as� que la descripci�n de forma sea un
     procedimiento completo del di�logo. Usted lo puede leer de un
     archivo o de una cadena (si usted previamente lo carg� a la
     cadena de cualquier fuente) el m�todo y lo muestra en una
     pantalla:

     oForm:     =    HFormTmpl    ():Read(    "testget1.xml")
oForm:Show()

     As�, permite crear realmente aplicaciones manejadas  por
    los datos.

2.  Los archivos de la carpeta \hwgui\utils\designer

    - designer.prg   -  Codigo fuente del Designer
    - designer.rc
    - editor.prg
    - hctrl.prg
    - hformgen.prg
    - inspect.prg

     -  designer.iml   -  Archivo de configuraci�n  principal
del Designer

    - blddesig.bat   -  BAT para compiler el Designer

     -  samples\example.prg     -   fuente  de  ejemplo,  usa
testget1.xml y testget2.xml
    - samples\bldexam.bat    -  BAT para compilar ejemplo

     -  samples\testget1.xml   -  forms del ejemplo,  creados
con Designer
    - samples\testget2.xml
    - samples\testdbf1.xml
    - samples\example.xml

    - resource/f_hwgprg.prg   -  script for prg output
    - resource/f_text.prg     -  script for old frm input

    - resource/widgets.xml    -  Archivo de configuraci�n con
el conjunto de �widgets�

  Hay  tres  ejemplos  de �forms� incluidos  -  testget1.xml,
  testget2.xml    y   testdbf1.xml,   que    implementa    la
  funcionalidad    de    los    ejemplos    que    hay     en
  samples/testget1.prg,        samples/testget2.prg         y
  samples/demodbf. prg.

3.  Algunas notas para aplicaciones HwGUI

  3.1.Hay una l�nea 'common' en los eventos de una forma,  se
     piensa para funciones, que se necesita para la forma y que se
     puede llamar de cualquier otro manejador de eventos de la
     forma.  Cada funci�n se debe terminar con la declaraci�n
     'ENDFUNC'. El 'Return' no es obligatorio, pero puede ser
     utilizado si la funci�n debe retornar alg�n valor.

  3.2.La  forma tiene una propiedad 'Variables� - usted puede
     agregar all� variables, que se declarar�n como 'Private' al
     principio de HFormTmpl():Show() y pueden ser utilizadas en
     todo manejador de eventos de la forma.

  3.3.Cada  �widget� tiene una propiedad 'Name' - este es  un
     nombre de objeto, que se declarar� tambi�n como 'Privado' en
     el principio de HFormTmpl():Show().

  3.4.Los  �widgets�,  que  tienen que corresponder  a  �tems
     'GET', tienen una propiedad 'Varname' - el nombre de  la
     correspondiente variable, que se declarar� tambi�n  como
     'Privado' en el principio de HFormTmpl ():Show().


