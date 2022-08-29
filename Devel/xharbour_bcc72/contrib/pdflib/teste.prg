func main
 Local n
 Local cFile
 Private AMSG, CIMG
 AMSG := {}
 set(105,1)
 set(106,1)
 CIMG := "logo.png"
 altd()
 for n:=8 to 8
 cFile := "leo"+strzero(n,2)+".pdf"
 * Cria documento
 PdfNew(cFile,8,842,595,1,1,,,{"DENI","DENI","DENI","DENI","DENI"})
 PdfStartPage( {"*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*"} , .T. )

* PDFPLACEIMAGE(CIMG, 1,1,57.73,0.8166,1240,1754)
 PDFPLACEIMAGE(CIMG,120,01,10,10,200,200)
 Aadd(AMSG,"*! Declaração de variaveis")
 Aadd(AMSG,"*! Variaveis totalizadoras")
 Aadd(AMSG,"*! Extração de dados")
 Aadd(AMSG,"*! PAGREC")
 Aadd(AMSG,"*! Formatação")
 Aadd(AMSG,"*! Formato do relatório")
 Aadd(AMSG,"*! Variaveis Fixas")
 Aadd(AMSG,"*! Mensagem de confirmação")
 Aadd(AMSG,"*! Mascaras dos campos e variaveis")
 Aadd(AMSG,"*! LayOut")
 Aadd(AMSG,"*! Cabecalho do primeiro Loop")
 Aadd(AMSG,"*! Detalhe do primeiro Loop")
 Aadd(AMSG,"*! Cabecalho do segundo loop")
 Aadd(AMSG,"*! Detalhe do segundo loop")
 Aadd(AMSG,"*! Cabecalho do terceiro loop")
 Aadd(AMSG,"*! Detalhe do terceiro loop")
 Aadd(AMSG,"*! Rodapé do primeiro loop")

 PdfDrawPage( AMSG )
 PdfEndPage()
 PdfEnd()
 next
 return nil
