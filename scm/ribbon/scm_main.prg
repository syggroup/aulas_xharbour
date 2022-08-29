#include "fivewin.ch"
#include "ribbon.ch"

REQUEST DBFCDX
REQUEST DBFFPT

static m_wnd, m_obj

function main()
 local m_bmp, m_mem


REQUEST HB_CODEPAGE_PTISO
REQUEST HB_LANG_PT

HB_SETCODEPAGE( 'PTISO' )
HB_LANGSELECT( 'PT' )

SET CENTURY ON
SET BELL OFF
SET DATE BRITISH
SET EPOCH TO 2000
SET CONFIRM ON
SET DELETED ON
SET EXACT ON
SET SCOREBOARD OFF
SET WRAP ON
SET EXCLUSIVE OFF
SET AUTOPEN ON
SET OPTIMIZE ON
SET STRICTREAD ON


 Public VERSAOATUAL:="Data da Ultima Atualização.: "+Data_Hora_ARQ(NomeExecutavel())+" Versão.:"+ GETFILEVERSIONINFO()
 Public xEMP       :="Sem Nome da Instituição"


 define bitmap m_bmp file ".\res\SCM.bmp"

 define window m_wnd title "SCM - SISTEMA DE CONTROLE DE MENSALIDADES Vs. "+ GETFILEVERSIONINFO() mdi

  ribbon m_obj

  ribbon system title 'SYGECOM' of m_obj
   
   insertquickbutton m_mem title "" bitmap "res\black.bmp" alpha of m_obj action m_obj:SetTheme(RB_BLACK)
   insertquickbutton m_mem title "" bitmap "res\blue.bmp" alpha of m_obj action m_obj:SetTheme(RB_BLUE)
   insertquickbutton m_mem title "" bitmap "res\silver.bmp" alpha of m_obj action m_obj:SetTheme(RB_SILVER)

   inserttab m_tab title 'Cadastro' of m_obj selected
    insertgroup m_group title 'Cadastro Associados' of m_tab

     insertbutton m_btn title 'Cadastra Associados' of m_group action (Cad_Associado("C","S"))
     insertbutton m_btn title 'Altera Associados' of m_group action msginfo('Pesquisa_Associado()')
     insertbutton m_btn title 'Pesquisa Associado' of m_group separator action msginfo('Pesquisa_Associado()')

     insertbutton m_btn title 'Relatorio' of m_group action msginfo('REL_ASSOCIADO("NOME")') split;
      action createMenuPopup(self,m_wnd,{{'Relatorio por Nome',{||msginfo('REL_ASSOCIADO("NOME")')}},{'Relatorio por Codigo',{||msginfo('REL_ASSOCIADO("CODIGO")')}}})

    insertgroup m_group title 'Cadastro Bancario' of m_tab

     insertbutton m_btn title 'Cadastra Banco' of m_group action msginfo('Cad_banco("C")')
     insertbutton m_btn title 'Altera Banco' of m_group action msginfo('Cad_banco("A")')
     insertbutton m_btn title 'Pesquisa Banco' of m_group separator action msginfo('Cad_banco("P")')

     insertbutton m_btn title 'Cadastro Setor' of m_group action msginfo('FRMcad_setor("C")')

    insertgroup m_group title 'Sistema' of m_tab
     insertbutton m_btn title 'Atualizacao' of m_group bitmap '.\res\update.bmp' alpha action msginfo('Atualizacao')

     insertbutton m_btn title 'Ajuda' of m_group bitmap '.\res\voice-support.bmp' alpha action msginfo('Ajuda_SCM()')
     insertbutton m_btn title 'Sobre a SyGeCom' of m_group bitmap '.\res\gohome.bmp' alpha action msginfo('sobre()')

     insertbutton m_btn title 'Sair' of m_group bitmap '.\res\lockstart_session.bmp' alpha action msginfo('Sair')




   inserttab m_tab title 'Mensalidades' of m_obj

    insertgroup m_group title 'Controles de Mensalidades' of m_tab

     insertbutton m_btn title 'Gerar Mensalidade' of m_group action msginfo('FRMcad_mensal("C")')
     insertbutton m_btn title 'Alterar Mensalidade' of m_group action msginfo('FRMcad_mensal("A")')
     insertbutton m_btn title 'Pesquisa Mensalidade' of m_group action msginfo('FRMcad_mensal("P")')
     insertbutton m_btn title 'Receber Parcela' of m_group action msginfo('Busca_parcASS()')
     insertbutton m_btn title 'Reimprimir' of m_group separator action msginfo('Reimp_carne()')

     insertbutton m_btn title 'Controle de Mensalidade' of m_group action msginfo('Faturas()') split;
      action createMenuPopup(self,m_wnd,{{'Faturas a Receber',{||msginfo('Faturas("A")')}},{'Faturas Recebidas',{||msginfo('Faturas("P")')}}})

   inserttab m_tab title 'Relatorios' of m_obj

    insertgroup m_group title 'Mensalidades Recebidas' of m_tab

     insertbutton m_btn title 'Geral' of m_group separator action msginfo('REL_PARC_GERAL ("P")')
     insertbutton m_btn title 'Total do Associado' of m_group action msginfo('Busca_REL("P")')

    insertgroup m_group title 'Mensalidades a Receber' of m_tab

     insertbutton m_btn title 'Geral' of m_group separator action msginfo('REL_PARC_GERAL("A")')
     insertbutton m_btn title 'Total do Associado' of m_group action msginfo('Busca_REL("A")')

    insertgroup m_group title 'Outros Relatorios' of m_tab

     insertbutton m_btn title 'Relatorio Mensal para Reuniao de Diretoria' width 120 of m_group action msginfo('Pesq_data()')


   inserttab m_tab title 'Uteis' of m_obj

    insertgroup m_group title 'Uteis' of m_tab
     insertbutton m_btn title 'Dados da Instituição' of m_group separator action msginfo('Dados_Instituicao()')
     insertbutton m_btn title 'Reindexar Banco de Dados' width 120 of m_group separator action msginfo('INDEXA()')

     insertbutton m_btn title 'Copia de Seguranca' of m_group action msginfo('Back_up()') split;
      action createMenuPopup(self,m_wnd,{{'Fazer Back-Up',{||msginfo('Back_up()')}},{'Retornar Back-Up',{||msginfo('Ret_Back_up()')}}})

     insertbutton m_btn title 'Calculadora' of m_group separator action msginfo('INDEXA()')
     insertbutton m_btn title 'Enviar email' of m_group separator action msginfo('INDEXA()')

     insertbutton m_btn title 'Imprime Capa' of m_group separator action msginfo('AVISO()')


     insertbutton m_btn title 'Configurar Impressoras' of m_group action msginfo('RunApplet_imp( "PrintersFolder" )') split;
      action createMenuPopup(self,m_wnd,{{'Ver Impressoras Instaladas',{||msginfo('RunApplet_imp( "PrintersFolder" )')}},;
                                         {'Adicionar Impressoras',{||msginfo('RunApplet_imp( "AddPrinter" )')}}})

    insertgroup m_group title 'Themes' of m_tab

     insertbutton m_btn title "RB_BLUE" of m_group action m_obj:SetTheme(RB_BLUE) SMALL NEXTLINE
     insertbutton m_btn title "RB_BLACK" of m_group action m_obj:SetTheme(RB_BLACK) SMALL NEXTLINE
     insertbutton m_btn title "RB_SILVER" of m_group action m_obj:SetTheme(RB_SILVER) SMALL NEXTLINE
     insertbutton m_btn title "RB_WORD" of m_group action m_obj:SetTheme(RB_WORD) SMALL NEXTLINE
     insertbutton m_btn title "RB_PUBLISHER" of m_group action m_obj:SetTheme(RB_PUBLISHER) SMALL NEXTLINE
     insertbutton m_btn title "RB_POWERPOINT" of m_group action m_obj:SetTheme(RB_POWERPOINT) SMALL NEXTLINE
     insertbutton m_btn title "RB_OUTLOOK" of m_group action m_obj:SetTheme(RB_OUTLOOK) SMALL NEXTLINE
     insertbutton m_btn title "RB_ONENOTE" of m_group action m_obj:SetTheme(RB_ONENOTE) SMALL NEXTLINE
     insertbutton m_btn title "RB_EXCEL" of m_group action m_obj:SetTheme(RB_EXCEL) SMALL NEXTLINE
     insertbutton m_btn title "RB_ACCESS" of m_group action m_obj:SetTheme(RB_ACCESS) SMALL

   inserttab m_tab title 'Painel de Controle' of m_obj

    insertgroup m_group title 'Painel de Controle Windows XP' of m_tab

     insertbutton m_btn title "Opções de acessibilidade"                      of m_group action msginfo('RunApplet( "access.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Adicionar ou remover programas"                of m_group action msginfo('RunApplet( "appwiz.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Propriedades de Vídeo"                         of m_group action msginfo('RunApplet( "desk.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Propriedades do fax"                           of m_group action msginfo('RunApplet( "fax.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Assistente para adicionar ou remover hardware" of m_group action msginfo('RunApplet( "hdwwiz.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Propriedades de Internet"                      of m_group action msginfo('RunApplet( "inetcpl.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Opções regionais"                              of m_group action msginfo('RunApplet( "intl.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Opções de jogos"                               of m_group action msginfo('RunApplet( "joy.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Propriedades de Sons e multimídia"             of m_group action msginfo('RunApplet( "mmsys.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Conexões dial-up e de rede"                    of m_group action msginfo('RunApplet( "ncpa.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "ODBC Data Source Administrator"                of m_group action msginfo('RunApplet( "odbccp32.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Propriedades de Opções de energia"             of m_group action msginfo('RunApplet( "powercfg.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Propriedades de Scanners e câmeras"            of m_group action msginfo('RunApplet( "sticpl.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Propriedades do sistema"                       of m_group action msginfo('RunApplet( "sysdm.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Opções de telefone e modem"                    of m_group action msginfo('RunApplet( "telephon.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Propriedades de Data e hora"                   of m_group action msginfo('RunApplet( "timedate.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Atualizações automáticas"                      of m_group action msginfo('RunApplet( "wuaucpl.cpl" )') SMALL NEXTLINE
     insertbutton m_btn title "Gerenciador de Dispositivos"                   of m_group action msginfo('ShellExecute("taskmgr.exe","open")') SMALL NEXTLINE

  m_obj:reindex()
  set msgbarex to 'Sistema de Controle de Mensalidades' of m_wnd clock date keyboard
  m_wnd:bPainted:={|hDC|drawLogo(hDC,m_bmp)}
 activate window m_wnd maximized on init m_wnd:oMenu:end()

return nil

function drawLogo(hDC,oBmp)
 Local nWidth := m_wnd:nWidth()
 Local nHeight := m_wnd:nHeight()
 Local aRect := GetClientRect( m_wnd:hWnd )
 Local nBottom, nRight
 Local hBmp := oBmp:hBitmap
 nWidth:=aRect[4]
 nHeight:=aRect[3] - 170
 xHeight := (nHeight-400)/2
 xWidth  := (nWidth-398)/2
 PalBmpDraw( hDC, xHeight, xWidth, hBmp, nHeight, nWidth )
 SysRefresh()
return nil

function open_menu(obj)
 local m_menu, m_row:=obj:nHeight
 menu m_menu popup // 2007
  menuitem 'blue' action m_rb:settheme(RB_BLUE)
  menuitem 'black' action m_rb:settheme(RB_BLACK)
  menuitem 'silver' action m_rb:settheme(RB_SILVER)
  menuitem 'office - word' action m_rb:settheme(RB_WORD)
  menuitem 'office - publisher' action m_rb:settheme(RB_PUBLISHER)
  menuitem 'office - power point' action m_rb:settheme(RB_POWERPOINT)
  menuitem 'office - outlook' action m_rb:settheme(RB_OUTLOOK)
  menuitem 'office - onenote' action m_rb:settheme(RB_ONENOTE)
  menuitem 'office - excel' action m_rb:settheme(RB_EXCEL)
  menuitem 'office - access' action m_rb:settheme(RB_ACCESS)
  endmenu
  activate popup m_menu at m_row,0 of obj
return nil

function createMenuPopup(obj,wnd,arr)
 local m_menu, m_row:=obj:nHeight
 local m_num
 menu m_menu popup 2007
  for m_num:=1 to len(arr)
   menuadditem(arr[m_num][1],,.f.,,arr[m_num][2])
  next
 endmenu
 activate popup m_menu at m_row,0 of obj
return nil

function MY_SHOWMSG()
return nil
