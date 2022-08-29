#include 'common.ch'
#include 'dbstruct.ch'
#include 'directry.ch'
#include 'error.ch'
#include 'inkey.ch'
#include 'fileio.ch'
#include 'dbinfo.ch'
#include 'hbclass.ch'
#include 'ord.ch'

#ifdef _NO_HWGUI_
   // não pode ter a hwgui.ch por que usa relatórios no formato txt
#else
   #include "hwgui.ch"
#endif

#define ePASS_EMAIL 'SENHA'      // DENIFIÇÃO DA SENHA DE EMAIL, PARA ENVIO DE ERROS E REGISTROS DO SISTEMA

#IfnDef __XHARBOUR__
   #include "hbcompat.ch"
   //#xtranslate curdrive()  => hb_curdrive()
REQUEST HB_GT_GUI_DEFAULT
#endif

#ifdef _XHBSQL_
   #define SQL_DBMS_NAME                       17
   #define SQL_DBMS_VER                        18
   #define eTipo_banco 'SQL'         // DEFINE O TIPO DE BANCO DE DADOS (DBF ou SQL)

   #include "sqlrdd.ch"
   #include "pgs.ch"        // PARA POSTGRESQL

   REQUEST SQLRDD
   REQUEST SR_PGS       // PARA POSTGRESQL
#else
   #define eTipo_banco 'DBF'     // DEFINE O TIPO DE BANCO DE DADOS (DBF ou SQL)
#endif

#define eKEY         'SENHA'
#define eVERSAO      '1.0079'
#define x_BLUE       16711680
#define x_DARKBLUE   10027008
#define x_WHITE      16777215
#define x_CYAN       16776960
#define x_BLACK             0
#define x_RED             255
#define x_GREEN         32768
#define x_GRAY        8421504
#define x_YELLOW        65535
#define CORPADRAO  COLOR_3DLIGHT+3
#define HB_EXT_INKEY
#define DC_CALL_STD 0x0020

#define eAnexos    {"CONTRATO","FOTO","CPF / CNPJ","RG","DOCUMENTOS","OUTROS"}

#define DRIVE_UNKNOWN     0
#define DRIVE_NO_ROOT_DIR 1
#define DRIVE_REMOVABLE   2
#define DRIVE_FIXED       3
#define DRIVE_REMOTE      4
#define DRIVE_CDROM       5
#define DRIVE_RAMDISK     6

#define eCST_ORIGEM    {"0-Nacional","2-Estrangeira(Importação Direta)","3-Estrangeira(Adquirida no Mercado Interno)"}
#define eCST_ICMS      {"00-Tributada Integralmente",;
                        "10-Tributada e com cobrança de ICMS por Substituição Tributária",;
                        "20-Com redução de base de calculo",;
                        "30-Isenta ou não tributada e com cobrança de ICMS por Substituição Tributária",;
                        "40-Isenta",;
                        "50-Suspensão",;
                        "51-Diferimento",;
                        "60-ICMS Cobrado anteriormente por Substituição Tributária",;
                        "70-Com redução de base de cálculo e cobrança de ICMS por Substituição Tributária",;
                        "90-Outras"}

#define eUNI           {"KG","TN","PC","LT","UN","MT","M2","M3","CX","GL","TB","PR","CJ"}
#define eAnexos        {"CONTRATO","FOTO","CPF / CNPJ","RG","DOCUMENTOS","TICKET","OUTROS"}
#define eAtende        {"PESSOAL - DIRETO NO LOCAL","VIA TELEFONE","VIA E-MAIL","VIA WEB","OUTROS"}
#define eItens_car     {"BI-TREM","BROOK","CAÇAMBA","CAMINHONETE","CARRETA","CARROCERIA","CONTAINER","GARRA","KOMBI","MUCK","PLATAFORMA","POLIGUINDASTE","ROLL-ON ROLL-OFF","TOCO","TRUCK"}
#define eAtivo_Inativo {"ATIVO","INATIVO"}
#define eTipo_Conta    {"Corrente","Poupança"}
#define eTipo_Prazo    {"A-Avista","A-Prazo ","Dinheiro","C/Cheque","Deposito"}
#define eDia_Mes       {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"}
#define eDia_Semana    {"Segunda-Feira","Terça-Feira","Quarta-Feira","Quinta-Feira","Sexta-Feira","Sabádo","Domingo"}

#define eItens_Mes     {"JANEIRO","FEVEREIRO","MARÇO","ABRIL","MAIO","JUNHO","JULHO","AGOSTO","SETEMBRO","OUTUBRO","NOVEMBRO","DEZEMBRO"}
#define eItens_Ano     {"2005","2006","2007","2008","2009","2010","2011","2012","2013","2014","2015"}
#define eItens_uf      {"AC","AL","AP","AM","BA","CE","DF","GO","ES","MA","MT","MS","MG","PA","PB","PR","PE","PI","RJ","RN","RS","RO","RR","SP","SC","SE","TO","EX"}
#define eItens_uf2     {;
[AC - ACRE               ],;
[AL - ALAGOAS            ],;
[AM - AMAZONAS           ],;
[AP - AMAPA              ],;
[BA - BAHIA              ],;
[CE - CEARA              ],;
[DF - DISTRITO FEDERAL   ],;
[ES - ESPIRITO SANTO     ],;
[GO - GOIAS              ],;
[MA - MARANHAO           ],;
[MG - MINAS GERAIS       ],;
[MS - MATO GROSSO DO SUL ],;
[MT - MATO GROSSO        ],;
[PA - PARA               ],;
[PB - PARAIBA            ],;
[PE - PERNAMBUCO         ],;
[PI - PIAUI              ],;
[PR - PARANA             ],;
[RJ - RIO DE JANEIRO     ],;
[RN - RIO GRANDE DO NORTE],;
[RO - RONDONIA           ],;
[RR - RORAIMA            ],;
[RS - RIO GRANDE DO SUL  ],;
[SC - SANTA CATARINA     ],;
[SE - SERGIPE            ],;
[SP - SAO PAULO          ],;
[TO - TOCANTINS          ],;
[EX - EXTERIOR           ]}
