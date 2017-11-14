# 19.04.17

Tittel: ikke bare wheezes

## Introduction

### Mulig struktur

**Jeg liker godt måten Matei Zaharia skrev introduksjon i sin PhD avhandling. Den skiller seg fra "IFI master/PhD intro" med å komme mye fortere til poenget og ikke bry seg om unødvendige ting. Ta gjerne og les hans intro og Edvard sin som brukte samme struktur.**

**Hvis vi bruker han som mal vil introen bli strukturert slik:**

**1. En introduksjon som vi ville brukt i ett paper (1-2 sider). Du kan feks bruke mye av innholdet i crackles paper introen. Og eksiterende tekst.**

**1.§: hva har skjedd i det siste som gjør deep learning analyse av lungelyder viktig/interessant i dag? Dvs du motiverer og definerer hovedproblemet i thesis. Ta gjerne og avslutt med en setning som sier dette.**

**2.§: Hva er "core challenges" for å løse problemet i 1.§?**

**3.§: Hva er related work og hvorfor løser ikke det core challenges?**

**4.§: Hva er vår løsning/approach?**

**5.§: Hvordan er den implementert? inkludert trent**

**6.§: Hva er "the long view", dvs hva kan det du presenterer i denne thesis brukes til utenom å analysere akkurat dette datasettet?**

**7.§: Thesis statement: hva er hoved contribution/ conclusion?**

**2. Problems with lung sound analysis**

**En litt mer detaljert diskusjon av den viktigste related work, der du beskriver hvordan lunge lyder analyseres i dag med ørene, regel baserte løsninger, og machine learning baserte metoder. Kanskje også deep learning i andre felt.**

**En oppsummering med issues som oppsummerer hvorfor related work ikke kan brukes.**

**3. "The approach" (en mer beskrivende tittel)**

**1.§: overordnet beskrivelse av approach**

**2.§: oppsummering av hvordan den løser problemer som related work ikke gjør**

**3.§: en skryteliste om hva som er unikt og bra**

4. (Mulig) Use of "the approach"

Kan godt nevne at det er ett kommersialiserings prosess på gang.

I training app

I smart app

I hjemme monitorerings devices

Eventuelt andre ting

**5. Summary of results

En figur + oppsummering av de vitkigste resultatene presentert på en slik måte at det er forståelig uten å ha lest en detaljert beskrivelse av approach, implementasjon, eller eksperiment metodologi**

**6. Thesis plan**

**Table of content med en setning per kapittel som kommer.**

### Kommentarer til tekst som er skrevet

**1.§ og 2.§ og 3.§ og 4.§ kan flyttes til "Problems"**

**En omskriving av §.2 kan fungere som første paragraf i introen (hva er main problem)**

**5.§ kan deles mellom the "The approach", "Summary of results" og "Use of approach"**

## Background

**Siden det vil være lesere med ulik bakgrunn (lunge lyd eksperter, computer scientists, macheine learning) inkludert de to sensorene så må denne gi en miks mellom introduksjon til viktige metoder og beskrivelse av state-of-the-art. Så jeg ser for meg at diskusjonene har en format av typen: hva er det (for dummies); hva er mulighetene (for ekspertene); hva fokuserer du på (for ekspertene).**

### 2.1 Machine learning

**1.§: important...in academia, industry, and medicine. Deretter setningen om "problems within ML" skrevet om til at dette er løsninger.**

**1.§: subfield kan kuttes ut**

**1.§: bør ha med training/ test/ validation. Og om vikigheten av data for ML.**

**1.§: bør ha med de forskjellige typen ML problemer: classification, clustering, prediction, etc. Supervised vs unsupervised.**

1.§: bør ha med en beskrivelse om hva feature selection er

**1.§: også en oppsumering av at i dette arbeidet ser vi på...**

**Ny 2.§: De viktigse metodene (SVM, ANN...). En setning om fordelene og ulempen ved hver av disse. Også en avslutende setning om at CNN, som beskrives senere, er valgt her fordi...**

**Ny 3.§: Om evaluation (del av eksiterende 2.§). Hvorfor vi bruker spec./sens. og hvordan vi kan finne fornuftige mål for disse.**

**Samlet vil da de 3 paragrafene si: hva slags ML problem det er; hvilken metode som er brukt; hvordan den er evaluert.**

Mangler mean average precision

#### Loss function

**Denne trenger å knyttes opp mot beskrivelsene overnfor. Hvilke metoder har en loss function? Hvorfor er den viktig? etc (for dummies beskrivelsen mao :)**

**Skjønner svært lite av innholdet, så det må noen andre sjekke.**

**Savner en setning om hvordan det gjøres dette i denne thesis? Lyd -> spectogram -> deep learning**

#### Gradient decent optimization

(tom)

### Deep Learning

**Bør ha en setning i begynnelsen som sier hva deep learning er og hvordan den er relatert til machine learning som beskrevet i 2.1.**

**human level accuracy: for hva slags problemer?**

**savner en diskusjon om at disse fungerer best / er designet for mye billed data. Og at de som har leder feltet (Google, Facebook, etc) alle sitter på mye slik data.**

**Bør også utdype behovet for regnekraft mer.**

**Må si at dette er approachen som benyttes her.**

**Bør ha ett delkapittel (og det samme i 2.1) om hva slags platfomer, libraries, og verktøy som finnes for deep learning, og hva som er state of the art.**

#### CNN

(tom)

### Classification vs detection

**Det er ikke selvsagt at leseren skjønner hvorfor denne er om bilder (dvs må si at Deep Learning er for bilder).**

**Er localization ett hardere problem en classification? Beskrivelsen sier det slik. Men er det ikke mulig å gjøre localization uten classification?**

**Hva slags problem er det som skal løses her?**

**Kan nevne at for vanlige bilder så tilbyr Azure og AWS services for å gjøre noen av disse tingene.**

### Related work

**Kanskje en annen overskrift. Sound classification?**

Savner related work om: andre typer medisinsk "deep learning" (pathAI, retina, etc). Poenget er å si at andre har gjort lignende ting, med bedre resultater, men at de har hatt ett lettere problem. Og samtidig si hvordan lungelyder skiller seg fra disse tingene.

#### Automatic speech recognition

**Spectorgam er ikke introdusert før i kapittelet etter.**

### Spectogram

**Sample rate i vårt tilfelle.**

**Kan godt vise ett eksempel spectogram her.**

#### Mel-scale

**Morten så på denne i forbindelse med crackles.**

## Methods

### Data collection

**Se gjerne hva og hvordan det er beskrevet i crackles paperet (og i retina analysis paperet)**

**"young and old": såvdit jeg vet er det godt voksne som blir invitert. Men kanskje jeg tar feil. Bør allikevel ha med alderen for de vi har lyder for.**

**They have collected -> They have recorded**

**17093 er feil, se crackles for oppdatert tall.**

**Det ble brukt 2 mikrofoner (se crackles paperet)**

**Multi-label forklares to ganger i paragrafen under table 3.1**

#### Breathing phase

**Uklart om dette er andre filer eller Tromsø 7 filer.**

### Manglende del-kapittel

Mangler informasjon om hva som er gjort med filen etter at at de annotert av ekspertene.

Dvs: hvordan har du valgt filene til ditt training data? Hvor mange er det i hver klasse? Hvordan er disse annotert? Hvordan er spectogram laget?

### Prototype

**Denne synes jeg kan komme etter beskrivelsen av deep learning metoden, siden den diskuterer ting ved metoden som vinduer som ikke gir mening enda. Jeg leser og kommenterer som om den kom etter disse.**

**Du kan gi sensorene midlertidig tilgang og skrive passordet her. Men samtidig kommentere at dette kun er for sensorene og ikke er ment som en permanent tjeneste.**

**Access due to file sensitivity: er ikke helt sant. Er mer at vi ikke ønsker å gi tilgang til upublisert data enda. Hvis det er sensitivt må du forklare hvordan det kan gjøres ikke-sensitivt slik at verktøyet kan brukes av andre.**

**Mangler beskrivelse av deployment, og ressurskrav for å kjøre tjenesten inkludert kostnad i penger.**

**Fig 3.2 shows.. implementation -> GUI**

Mangler beskrivelse av breathing phase funksjonalitet

### Full file classification

**Her ble jeg forvirret, fordi jeg vet dette er noe som ikke fungerer (det vet ikke andre lesere). Det kan løses med en intro setning som sier hvorfor dette forklares først og hva som kommer senere. Eventuelt ta dette etter at den beste metoden er forklart.**

**Hmmm...jeg trodde det ble vist en tabell i dagens lab møte om at dette ikke fungerte? Og ikke 75% accuracy?**

**Hva er "some methods" som ble brukt?**

**Det er vanskelig å tolke resultatene som blir presentert før methods (og i methods kapittelet).**

**Hvorfor tas multi-label vekk? (er litt selvsagt, men bør allikevel forklares)**

**Hvordan ble undersampling gjort? og hvorfor?**

#### Manglende del-kapittel

Hva slags model er brukt (CNN etc). Og siden det nevnes senere; hva er computation (resource) need for denne?

#### Model architecture

**Hvorfor gir det mening å bruke en sang database model for lungelyder?**

**" Instead we adapt their architecture and try to perserve structure and size.": skjønner ikke hva som menes med structure and size. Og jeg liker ikke bruken av ordet "try". Vet du om det fungerte eller ikke?**

**rest of architectures -> the other**

Hva er ADAM (optimizer) og hvordan fungerer den?

**Hva er forskjellen for 14s vs 15s filer?**

**Paddes det for 15s eller 14s filer (teksten sier 15)**

Hva slags resolution brukes i "multi resolution spectogram"?

Hvordan oversamples det? (iterasjoner og andre parametere)

Inter calss augmentation er ikke ferdig skrevet

Ensembling: hvem har vist at det er nyttig? Og jeg skjønner ikke hvorfor det gir mening med ensemble for five *equal* models?

### Expiratory wheeze detection

(kom hit sist gang)

# 01.05.17

## Methods

**Starter fra begynnelsen av Methods siden det er noen endringer der**

**Generelt: husk at leserene ikke har lest prosjektoppgaven din. Så alt som står der må beskrives, med mindre det er små detaljer som ikke er nødvendig for å forstå det som beskrives her, eller det er noe som ble gjort som ikke er interessant nok til å beskrive her.**

### Expiratory wheeze detection

(noen av de tidligere kommentarene er ikke fikset enda)

### Breathing phase annotation

**Tittel er misvisende siden det også beskrives ting som er gjort med filene utover annotation**

Hvem har annotert filene? Kun Cristina? (se crackles for hvilke detaljer som bør være med).

Hvordan ble filene valgt? Av hvem? Er crop alltid på slutten?

**Crop file to 2000Hz forklares to ganger**

**Husker ikke om behovet og nytten av breathing phase annotation er motivert og forklart i intro/ background. Hvis ikke, må det legges til.**

### Real world dataset

**(tom)

Og jeg er ikke sikker på hva som er tenkt inn her**

### Wheeze detection

**Generelt: Jeg forelslår at du skiller mellom beskrivelsen av wheeze detection metoden og hvordan den er evaluert. Tenk på første del som en beskrivelse for de som vil implementere denne for sitt eget datasett, og andre del for de som vil gjenta ditt eksperiment med enten sitt eget datasett eller vårt datasett.**

**our/my work descrbied in [11]. Jeg synes det er viktig å skille mellom eget og andres arbeid.**

**[11]: her må du kort oppsumere hva som ble gjort der. Og hvorfor det er behov for å gjøre mer, og hvordan arbeidet i masteren skiller seg fra tidligere arbeid (noe av dette er allerede beskrevet).**

**Our own annotaions: usikkert hvem "we" er.**

**attempted -> used**

**Trenger ikke å vise frem til resultater. De kommer vanligvis etter methods i vitenskapelige arbeider :)**

#### Implementation details

**Generelt: lurt å få noen andre en meg til også å lese denne siden jeg ikke forstår alle implementasjons detaljene.**

**Generelt: det er ikke klart for meg hvordan alle de ulike valgene som beskrives her gjøres for implementering av en Deep Learning metode. Så jeg savner en overordnet beskrivelse som setter alle i context. Feks en slags punktvis liste over hvilke valg som kan/må gjøres og hvordan disse henger sammne. Dette kan forklares i feks background.**

**Hvilken previous work? Og du må forklare dette uansett. Leseren skal ikke trenge å finne frem related work for viktige detaljer (men er greit å henvise til related work for detaljer som ikke er vesentlig for å forstå metodlogien).**

**Hvorfor redusert til 10? Og redusert i forhold til previous work? Hva var den opprinnelig?**

**Jeg skjønner ikke hvorfor en slower (i mitt hode betyr det at execution time er lenger) gjør det enklere å soppe for å unngå overfitting.**

**Vanskelig for meg å si om det er noe i Appendix A som ikke er beskrevet her.**

**"x number of experiments": ville snudd om på dette, og heller forklart hva som er de viktigste parameterene, også senere forklart hvordan verdiene for disse er evaluert. Så det mangler en beskrivelse av hva data augmentation er, og hvordan denne kan endres, og hva fordelene og ulemepene er. Og det samme for window size, og window stacking. Sistnevnte er jeg usikker på om er nevnt før i rapporten.**

Ikke skrive "we attempt". Enten er noe gjort eller ikke. Attempt hører til i sistnevnte (prøvde, men fikk ikke til)

Må si hvordan SDG og RMSProp velges (eller vise til ett Appendix der dette står, hvis det er mange detaljer). Disse to er ikke beskrevet før, og jeg har ingen ide om hva det er.

#### Data preprocessing

**These experiments -> det er en metode som beskrives. Evalueringen av denne kommer senere.**

Husker ikke om Mel spectogram er beskrevet før. Og hvorfor brukes disse? Fordeler og ulemper?

**"slice out": er dette korrekt engelsk?**

**"We do not use" setningen er veldig tunglest. Og jeg forstår ikke alle detaljene i den og neste setning. Dette tror jeg kommer av måten det er skrevet på.**

#### Model architecture

**"is the same": same as in?**

**not see much gain -> We did (hva slags) tuning of the architecture, but we did not see any improvements. Noen ide om hvorfor den er god nok?**

**Tregner referenasne til VGGNet**

**previous work: si først hva som er gjort her, deretter hva som er prøvd tidligere. Det mest interessant er alltid arbeidet i paperet/rapporten man leser om.**

### Full file classification

Første setning: Hva er motivasjonen for å gjøre full file classification? Hvordan skiller det seg ut fra det som ble forklart i forrige del-kapittel?

preferable method...expert classified files: ikke sikker om jeg kjøper denne. Kan jo si at du kan si en fil har wheezes eller ikke basert på windows metoden.

small dataset...dimensions: oppgi tall

75% ... skjønte jeg det rett skulle disse tallene bli oppdatert, så jeg hopper til neste kapittel.

### Breathing pahse detection

less important information.; ikke vanlig å si det slik. Si heller "including, (de viktige tingene)"; så er det implisitt at det er noe mer.

Hva er some limitations?

to see: to detect eller noe sånt (det er vel ikke noe som gjøres visuelt av ett menneske?)

We split... er en beskrivelse av experiment metodologi og ikke metoden, så det kan flyttes til slutten.

"sent to Aveiro": her (senere) må det beskrives hva de gjør med det.

#### Model architecture

Fig 3.2: veldig liten skrift i figur tekst

first/second equation -> first/second part in equation

Jeg henger ikke med i beskrivelsen av formelen. Men det kan være min manglende kunnskap i emnet.

#### dataset

Flyttes til eksperiment metodologi beskrivelse

#### Implemntation details

Tittel: kan kutte details; imeplementation er alltid om details :)

Andre §, så skjønner jeg ikke det med inference. Hva er det? Hvorfor oppstår det?

### Prototype

Tittel: Lung Ausculatation Training Tool

is intended -> is

Hvordan skal brukerene bruke LATT og til hva?

## Evaluation

**Ny tittel: Results**

**Trenger en intro til hva slags resultater som vises. Både før del-kapittelene og i hvert del-kapittel.**

For hvert del-kapittel så bør strukturen være: dette spørsmålet besvares fordi at; resultatene viser at; svaret på spørsmålet er;

Generelt: det vanlige i medisin er å se på Specificity og Sensitivty. Foreslår at disse også brukes her. Eventuelt at alle 3 brukes: Precision, Recal/ Sensitiviy, Specificity.

### Wheeze results

**Tittle: Wheeze detection**

**Replicate previous work: jeg ser ikke at previous results er tatt med i tabellene.**

**For each experiment...change a small: kan kuttes ut. Dette er slik det vanligvis gjøres (med mindre man har ett mer komplekst eksperiment design)**

**Table 4.2 diskusjonen er om Table 4.1?**

**positive effect on experiment -> ...on results/ precision-recall**

**Trenger å sette disse resultatene i kontekst. Hvordan er det sammenlignet med mennesker?** **Er det bra nok for feks LATT?**

### Full file results

Tittel: Full file classification

### Breathing phase results

**Tittel: Breathing phase detection**

**Her brukes accuracy og ikke precision-recall (eller den bedre sensitivity-specificity).**

# 01.05.17

## Introduction

**1.§: kan kutte andre setning (The success)... Ikke sikker at alle andre metoder er ineffecient.**
*Den har gjort det, men burde jeg ikke si det uansett?*

**1.§: Medical data analysis... og utover passer ikke helt inn. Forslag til endringer fra og med den setningen: This developement has opened up... for new medical fields. But a major limitation is available data, and the need to adapt...to new data types and application domains. As a result, most work for domains with big public image datasets...need to develop & evaluate ... that works well for new fields such as lung sounds.**



**Medical data analysis is a time consuming process which requires manual work and training. With over 300 million asthmatic patients worldwide, automatic lung sounds analysis is highly highly sought after. Abnormal lung sound detection is a difficult medical problem, inexperienced physicians may classify lung sounds differently.  \cite{Aviles-Solis}. As a result, there is a growing demand for creating a robust and consistent systems that utilize recent technological advances such as deep learning for medical data analysis.**


**2.§ Several -> Nummer. Og bruk gjerne en liste for disse. Det gjør det enklere å skille disse fra hverandre og huske på hvilken av challenges som existing systems ikke løser.**

**2.§: hvor mange av disse er "generic challenges"? Er det mulig å skrive denne om slik at "core challenges" gjelder for alle medisinske domener, mens eksemplene er for lung sounds?**
**Several challenges need to solved to develop a robust automatic lung sound classification system. The first one is a need for a reference database with lung sounds.
Detection and classification of abnormal lung sounds is difficult for humans. A high quality reference database with consistent classification is needed to define and understand abnormal lung sounds. A second challenge is robustness, abnormal sounds may appear only in a short time frame, crackles typically last between 5-40 ms, and wheezes are typically longer than 250 ms. The breathing phase that abnormal sounds occur in is also valuable. These short events can be buried by other data if the audio file is long. Recorded lung files can contain other bodily sounds and environmental sounds. A solution need to correctly handle different types of noise such as talking, bowl movements, coughing or stethoscope rubbing. Lastly, the system needs an interface that can expose the classification capabilities to its end users.**

**2.§: a solution... Solution tas senere. Så denne og neste setning (Lastly..) bør skrives om slik at de beskriver en challenge.**

**3.§: "can perform" er for unøyaktig. Kan si det generelle: Existing systems solve some of these challenges...but not all.**

**3.§: generelt for alle "existing system". Hva de gjør, hvorfor dette ikke løser en/flere challenges. Det blir kanskje for detaljert; noen av detlajene kan flyttes til 1.1**

**4.§ We propose...det du har gjort med CNN her.**

*Også at det finnes en database, og de viktigste delene i metoden som fungerer best. Jeg synes det er for mye ikke-dine-ting her, disse kan flyttes til 1.1. Dvs det som er i 6.§ og 7.§ her (Our solution... & In thesis...), men endel kortet ned.**

**4.§: LATT ville jeg flyttet til neste paragraf siden det er en demonstrator av nytten for metoden.**

**5.§: "the bigger picture tas til slutt".**

### Problem

**Tittel: problem with lung sound analysis**

**Hva er eksiterende måter å gjøre dette på? Og hvorfor er det no good.**
**1. Stetoskop og ørene**
**2. Diverse medical devices, inkludert spiroskop(?) Pulmo track**
3. Smart app + bluetooth stetoskop
4. Rule based analysis
5. Machine learning based analysis

**Mye av esksiterende tekst kan gå inn i #1.**

**"With a the growing amount..." og utover passer ikke inn her. Men kan flyttes til 1.3 som en application av metoden.**

### Deep learning approach

**Tittel: mer beskrivende: CNN for lung sound spectograms eller noe slikt**

**Her beskrives kun metoden. Og ikke hvordan den er evaluert.**

**Det bør sies hvorfor dette er bedre en previous work, men kun med 1-3 setninger. Den andre paragrafen bør skrives om hva metoden gjør og hvorfor det er bra.**

### Potential applications

(tom)

### Summar of results

(mangler)

### Thesis plan

(mangler)

# 02.05.17

## Background


### Machine learning

Many believe... mangler referanse (den Science special issue er fin å bruke)

**For example image,... her mangler det noe. Eller så menes, Examples include**

**categories...depending on data: er det virkelig data som avgjør dette? Og hva menes egentlig med data?**

**The classes of each sound are known. Kan ha med i en parantes hva disse klassene er.**

**Mangler en kort beskrivelse av reinforcement learning (siden de to andre categories er presentert)**

**Siste paragraf -> Summarized, our problem is acoustic...**

#### Methods

**In our problem -> For our noe-annet-en-problem**

**For simplicity...binary: Her er det uklart om du gjør en assumption for forklaringen av metodene, eller for å løse lung sound classification. Hvis det er sistnevnte så må det forklares hvorfor en slik simplification er mulig.**

Motivatin behind SVM: er uklart. The goal?

Too many learnable...: mangler noe her. Dvs hva er en parameter i SVM, og hvordan bestemmer man hvor mange det skal være.

**Random forest -> A commonly used decision tree...random forest.**
*random forest er ikke et decision tree*

**try to understand -> learn**

ANN beskrivelse mangler (siden de to første SVM og decisin tree var beskrevet). Dette kommer senere, men det må sies. Eventuelt kan det vurderes å flytte det del-kapittelet slik at det kommer etter denne.

Når er SVM, random forest, eller ANN best? Hvordan velger man best metode?

#### Magnelende del-kapittel

Jeg savner ett delkapittel om hvordan man går frem for å implementere en machine learning algoritme. (få tak i data, cleaning, annotation, feature selection, ...)

#### Evaluation

(tom)

### Deep learning

DNN, RNN, LSTM kan oppsumeres med 1-2 setninger her. Og vise til en lengre beskrivelse av CNN som kommer senere.

We process several seconds: seconds?

### CNN

Ingen endringer siden sist tror jeg.

### Related Work

Mangler en kort introduksjonsparagraf som sier hvorfor speech recognition, acoustic classification, etc er relevnat.

Ingen endringer siden sist tror jeg.

# 23.05.17

## Introduction

**C1: er de ikke i markedet fordi de er for dårlige eller at de som har laget de ikke har gjort det. Er kanskje bedre å observere at de ikke er på markedet og spekulere i at det kan skyldes at de ikke er god nok.**

**C2: Eko devices eller en eller annen journal system kan ha noe som er større.**

**C3: Long = whole(?) files fungerte vel ikke så bra? Så det kan tas vek. Hvis long != whole, er det bedre å si our approach for long...two parts...**

**C4: integrated...prototype: si heller implemented in a service/server/noe-annet**

**C5: blir for detaljert her. Noen kan kanskje integreres i paragrafen over, eller så kan det flyttes ett annet sted.**

**C6: blir litt rart å ha dette med her**

**C7: Snu det til: Our system has been evaluated by...experts...også resulatet av den biten.**

# 26.05.17

## Abstract

**I en såkalt structured abstact ville de fire paragrafene beskrive:
1. Background and objectives: §1 dekker background, men objectives (mål) er ikke klart beskrevet.
2. Methods: §2 og §3 beskriver dette
3. Results: §3
4. Conclusions: §4**

**Det kan være lurt å lese tenke over strukturen i abstracted til JAMA retina image paperet.**

**Imprvoements in algorithms er uklart. Hvilke algortimer, deep learning eller noe annet?**

Slå sammen to første setninger...too complex, and hence have been applied to new fields.

**"images used" -> deep learning methods can use large image datasets to train models...**

**can be used -> is recently used**

**To siste setninger i §1: slå sammen. Si heller noe sånt som: new fields requires solving...noe...noe-annet...enda-mer. Dvs hvilke problemer du har løst. Dette fordi...**

**requires new approaches": er uklart hvorfor det krever, og hva en ny apporach er (feks ett altenrativ til deep learning), og ...**

**"new challenges": sies ikke noe om hva disse er.**

**"an approach": hva det er må beskrives her (det kommer en beskrivelse senere),.**

**relevant work -> related work/ previous work**

**Wheras...out work show how to apply deep learning -> Previous work have used...(punktum).** **En setning om hva problemet som deep learning løser som de andre ikke har gjort.**

**"We use the biggest known"... Sjekk hvordan vi har tonet dette ned i crackles paperet. Vi bruker en del av ett stort represetnativt datasett, etc**

**We threfore believe... litt skummelt å hevde dette i abstract når det ikke er vist eksperimentelt. Kan la det stå litt åpent ved å ikke si det eksplisitt, men hinte til det ved at vi har brukt ett mer realistisk datasett.**

**"We achieve...": første setning er methods, dvs en beskrivelse av approach.**

**state-of-the-art research -> state-of-th-art CNN... (og ta bort mpre specifically)**

**"e.g." mener jeg er brukt feil.**

**I presentasjonen av results er første gang wheezes og breathing phase nevnes. Disse bør beskrives under "methods" eller "objectives" dvs hva apporahc gjør eller skal gjøre (hvis objective)**

**Sjekk hvordan JAMA retina presenterer sine resultater (jeg har ikke gjort det, men kanskje har de noe nyttig der)**

**"To do this, ...": hører hjemme i methods**

**"techniques...highly imbalanced...": hva er disse technqiues og hvor bra virket disse?**

**The approaches...: Hva er konklusjonen om brukbarhet for problemet som skulle løses i thesis? Er det noen applikajsoner for arbeidet? Det som følger er hva *mer* det kan brukes for.**

**"The litereature...": foreslår jeg at du kutter ut.**

**"The detailed documentation...": dette er noe alle vitenskapelige paper/thesis bør tilby (selv om mange feiler), så dette kan også kuttes ut.**

## Conclusion

**Tittel: Conclusions and Future Work. Evnetuelt ha future work i egen del-kapittel**

Merk at det er mulig å gjennbruke (kopiere) ting mellom abstract, første del av introduction, og conclusion. Nå er det 3 ulike måter å selge arbeidet på.

**Jeg ville ikke brukt forkortelser her, siden noen kan hoppe direkte til Conclusion etter å ha lest abstract.**

**"AED is a field...": avslutt med å si at det allikevel er ett viktig felt**

**"that can detect...": er også gyldig for random guess. Si hvor bra de gjør det. Og hvor bra det er i forhold til mennesker.**

**"We argue...": hva er argumentene? Sjekk også kommentarene i abstract om "Conclusions" paragrafen der.**

**"to problems outside...": hvilke? og hvorfor?**

**Litt overaskende at det ikke sies noe om at approach er tenkt kommersialsiert og at det allerede har utløst 1M i funding, og interesse blant MH for å bruke den.**

### Future Work

**Faster RCNN: referanse? Og hvorfor gjøre dette arbeidet?**

**"more work in annotations..": hva slags arbeid?**

**"We will get access to...": Hvorfor det? Fra hvem? Og hva har det å gjøre med Faster RCNN?**

*Er det noen svakheter du vet om i arbeidet som er gjort? Eksperimenter som ikke er kjørt? Andre ting du ikke rakk å impleementere? Andre ting sensor kan mene at du bør gjøre? Her er stedet å komme med unnskyldingene.*

## Results

**"will present and discuss...": diskutere også siden det er ett eget kapittel om det?**

**"Results are reported...": si først hva du måler og hvorfor. Det er enklest å skrive det (først) som en liste med spørsmål som skal besvares.**

**Jeg skjønner poenget med precision/ recall beskrivelsen. Men her er det forvirrende. Kan si at det brukes p/r og at du senere diskuterer sens./spec. og andre ting. Dette bør disktueres, selv om det er "lett" å konvertere (feks er det slett ikke sikkert jeg vile fått til konverteringen).**

*Hvis det er 5-10% variasjon må det rapporteres.*

### Experimental Setup

**Kan flyttes til Methods.**

**Computers...: OS? Versjon av bibliotek, etc**

**Computers...: Her kan du si hvilke eksperimenter som brukte hvilken maskin. Ellers må det beskrives for hvert del-kapittel.**

### Wheeze detection

**breathing phase...: er ikke beskrevet enda. Så er bedre å sammenligne der den beskrives. Og jeg skjønner ikke "two reasons", og det tror jeg ikke noen andre gjør siden det diskuteres noe som vi ikke vet om (enda).**

**In this system we want to... -> We show the results...**

**3 experiments: hvorfor er det interessant å vite dette? (dvs hva er spørsmålet). F.eks. ...impact of different windows sizes for... Eller How does windows size influence the...**

**Lastly,...: da blir det vel 4 ting?**

### Window Size

**Jeg liker godt titler som oppsumerer resultatet. Så noe sånt som: Two second windows give ....**

**"A problem that has been experience": av hvem?**

**5-30: non-overlapping windows?**

**A motivation: vår motivasjon? Generelt er det bedre å bruke active voice, siden det gjør det klart hvem det er som har gjort/ ment/ tenkt noe.**

**most of these: du finner tall for dette for våre filer.**

**Doubling...will halve: will halve tror jeg ikke er korrekt engelsk. Og jeg skjønner dette, men hva er ulempen?**

**Table 4.1: fotnote 2 er ikke i tabellen.**

**Table 4.2...: menes det 4.1?** **Og ingen av de har accuracy med. Det høres også ut som at konklusjonen i Table 4.1/4.2 er at det beste er å ha størst mulig window. Først etter å ha lest neste paragraf blir det klart at det er en BUT der.**

**Table 4.1: rar skalering siden 2.5 seconds ikke er med**

**sweet spot -> noe-annet**

**Er en rar konklusjon at selv om 3s er bedre så bruker vi 2s siden vi tror den er bedre (til tross for våre egne resultater som viser det motsatte).**

**Hva med performance implications?**

### Improvements

**Improvement til hva. Så samme kommentar ti0
**"techniques outlined...": hvilke tekniker. Blir for mye arbeid for leseren å bla tilbake til 3.3, så oppsumer de her. Og hvis de kun er outlined der, hvor er den ordentlige beskrivelsen?**

**Hvorfro multiple spectorgrams... og ...ensemle? (-> spørsmål)**

**Table 4.2: fotnote 2 er ikke med**

**5% increase, men med hvor mye variasjon i resultatene (dette må tas med siden den er stor)?**

**by % in all: tall mangler**

**Hva er konklusjonen til resultatene i Table 4.2?**

Table 4.3 detail...: forstår ikke hvorfor disse resultatene vises (men det er sikkert en god grunn).

Previous work...: du kan ta med de resultatene i tabellen. Samt naive classifiers som random guess, og "allitd ja/nei".

### Related Work

**Merkelig tittel. Antar det menes comaprision to previous results eller noe sånt.**

**on our dataset -> using our dataset**

**Our results...: denne paragrafen er tung å lese, siden:  Our results are comprable...comparing our results...is therfore difficult. Hva er det denne paragrafen er om, og hva er konklusjonen?**

**...PulmoTrack...: hva er denne paragrafen om, og hva er konklusjonen. Du kan tenke på hver paragraf som noe som har en introduksjon setning, diskusjon/utleding, og konklusjon.**

**### System Requirments**

**Requirements er noe som vanligvis defineres på forhånd. Evaluerings resultater viser om systemt tilfredsstiller disse.**

### Breating Phase Detection


Tas senere.

# 27.05.17

## Discussion

Mangler en introduksjon som sier hva som blir diskutert.

### Problems with classification

**Uklar tittel**

**results are not sufficient: hva betyr dette og hva er det som ikke er bra nok? Precision? Recall? Accuracy? Og hvorfor.**

**could be a result of curse... -> may be / is probably...caused by curese**

**curse...: forklar hva det er og hvorfor det er ett problem her**

**decreasing resolution: hvorfor kan man anta at det vil virke?**

**reduction of the image -> reduced resolution**

**pretrained...size of the images: hva er vanlig limit?**

**Og hvor store er våre bilder i henhold? Og hvordan gjøres dette med feks high resolution pateologi bilder?**

**not straight forward: hvorfor?**

**explored in the future: har du gode ideer til hva som kan gjøres?**

**smaller slices: = sliding window?**

**an detection approach: virker unøyaktig**

**hvorfor hjelper slik annotation?**

**Our experimetns -> Our approach poor performacne on...**

**It is also clear -> However, we believe...**

### Wheeze annotations

**by doctors -> by lung sound experts. Og hva slags problemer kan dette føre til? Hva er løsningen på det?**

**Inspecting the predictions: hvordan?**

**Previous work...: viktig å poengtere at det ikke ble brukt CNN og spectograms der.**

**Også litt merkelig å snakke om crackles i kapitellet om wheeze annotations. Savner også en beskrivelse av forskjellen mellom disse to, og hvorfor din approach ikke kan brukes direkte for å finne crackles.**

### Bigger and better datasets

**hvor stor er helle datasetet? Hvem er they? Her passer det å komme med en beskrivelse av de tre nivåene med grading som er gjort. Hvilke nye possibilies?**

### Commercial Potential

**Savner en diskusjon om applictions av approach (men det er kanskje beskrevet i Methods). Særlig med hensyn til om resultatene er gode nok for forskjellig bruk.**

**Her ville jeg sagt at ett selskap kommer til å bli startet opp.**

### Kappa etc

Savner en diskusjon om hvordan metoden kan videre evalueres. Kappa, "JAMA", etc for å få resultater som kan sammenlignes med andre studier og som legene skjønner. Her kan også resultatene oversetttes og diskuteres som sensitivty og specificity.

# 29.05.17

## Abstract

too complex...: for hva? (rules based approaches?)

symptoms and diseases...: litt uskker på om det finnes noen som har klassifisert symptomer. Har du referanser til dette (som kan legges til i Introduction). En tryggere ting å å bruke den patologi-bilde konkuransen og si at for noen type analyser så gjør deep learning det like bra som mennesker (eksperter).

This development...: noe sånt som However, ... many unexplored areas such as lung asculation (eller-hva-det-nå-het)...

I JAMA sier de dette: "Application of these methods to medical imaging requires further assessment and validation." "Objective: To apply deep learning to create an algorithm for automated detection of diabetic retinopathy and diabetic macular edema in retinal fundus photographs". Kanskje kan du si noe lignende

**Det med Tromsø 7 kan flyttes til neste paragraf (er en del av metoden)**

**Related work -> Previous work. Også bør "rules based" tas med hvis denne ikke dekkes av too complex ovenfor**

**model, our work... -> model...: det om "our work shows" er allerede sagt i første setning i paragrafen.**


**We belive...: er noe som bør bevises i en thesis.**

**Our approach...: bør være andre setning i paragrafen, siden det er viktig å si hva approach er før fordelene beskrives. Også bør det være tall for hvor stort det er.**

**"For wheeze...": denne setning beskriver metodologi og bør flyttest til forrige paragraf.**

**Our approached acheived: apporached; og order wheeze mangler**

**Furthermore, ...: dette er ikke ett resultat, men methods. Og det mangler results for det som ble gjort der.**

**"Can detect"..."are promising...": sier ikke noe om hvor bra det fungerer. Hvordan er det vs mennesker (vi har en diskusjon om akkurat dette nå for crackles paperet).**

**"can be integrated...": Further work to determine..."**

**Sjekk også hvordan JAMA konkluderer**

## Background

Generelt: så savner jeg koblinger til ditt arbeid her. Leseren vil lure på hvorfor du skriver om dette. Dette kan løses med å legge til en setning til de fleste paragrafene der du sier hva du har gjort/brukt. Samt å bruke lung sounds som eksempel der du kan.

will describe -> describes. Will describe er noe som skjer i fremtiden. Thesis eksiterer i nåtid.

**define the field: ikke define**

can be performed on -> for

Finally ... -> Finally, we describe machine learning methods... for Acoustic Recognition.

### Machine learning

**for example in industries... -> for example in...**

**can solve problems -> solves problems...better than rule based...**

**cancerous or not: trenger referanse. Pluss at det må sies at det er tumor bilder.**

**In finance & In insurance: begge trenger referanse**

**(for generelle referanser om nytten av machine learning så er Science Special Issue ett godt valg)**

**Machine learning is the study...: kan være andre setning i paragrafen. Dvs si først hva det er, også eksempler etterpå.**

**...AI revolution: trenger referanse. Og denne bør utdypes mer. Men fungerer kanskje bedre om den kommer før eksemplene.**

**"Some of the most": flyttes til neste paragraf.**

**task with fruits: bedre å bruke lung sounds som eksempel så mye du kan. Både her og andre steder.**

**Hva er accuracy, precision, recall & F1-score? Ser at det forklares senere, så enten vis til den eller ta det bort her.**

**Our problem is acoustic...: synes det er bedre å flette innholdet i denne i de tidligere paragrafene.**

#### Supervised Algorithms

**is binary...: sant for lung sounds?**

**do not regard: er dette korrekt engelsk?**

**relation to each other: høres ut som det er 2 pixel**

**CNN blir introdusert i det skjulte her. Setningen passer ikke helt inn der den er.**

**Hva slags evaluation metrics? Det som beskrives nedenfor?**

**Figuren mangler nummer. Og teksten er veldig liten.**

#### Supervised Evaluation

**definesd in 2.2.2: section 2.2.2?**

**Accuracy: hva er problemet med skewed dataset?**

**car/bike -> lung sounds**

**Spec. & Sens: Sensitivity = Recall = TP/(TP+FN). For å gjøre det klart.**

### Deep Learning

**Savner en beskrivelse av hvorfor dette egner seg så godt på GPU og spesialiserte chips**

#### CNN

**In this section we will describe... -> We use ConvNet, which is...: dette ble også sagt ovenfor.**

**has shown success -> works well**

**They have... -> ConvNets are based on...**

**That researched: typo & [25]?**

**Figure ??**

**Fig 2.2: since...has 32 -> If...has 32...then**

#### Loss Function

**Equation 2.1: har vært mange equation før denne.**

### Classificatoin vs detection

**In our work...our problem: er ikke det to ulike problemer? Denne setningen bør forklares.**

**While we are...inference time...several seconds...5 frames per second: jeg skjønte ikke hva dette har med "Classification vs detection" å gjøre.**

### Machine Learning Framework

**Noe av dette er methods. Dvs hvilke du har brukt, og hører derfor ikke til i Background.**

### Spectogram

**This thesis will represent...: er dette illustrasjoner i teksten eller også det som er brukt av systemet?**

**The creation of spectograms: her beskriver to Methods, så dette hører ikke til i Bakckground.**

**Mel-scale: skjønner ikke hvorfor denne er med? Er det brukt eller ikke? Hvis ikke, kan det tas bort.**

### Acoustic Recognition

**Tittel -> Related Work in Acoustic Recognition**

**Most work...: sier det samme som forrige setning.**

**related fields...: fields innen for acoustic recognition?**

#### Automatic Speech Rec.

**lot of success due to rapid progress: success = rapid progress**

## Methods

Mangler tall i overskriften

**data collection, class distribution: + data annotation**

**how to train -> how we train**

**describe experiments -> describe experiment methodology**

**Tromsø Study: trenger ikke å nevnes enda**

**design and implementation of a prototype: men ikke en beskrivelse av selve "analysis system". Og jeg ville brukt application fremfor prototype.**

**When we refer to...: litt merkelig.**

**...shell commands: detalj som ikke trenges å beskrives enda**

### Dataset

**Different ages: viktig å poengtere at barn ikke er med, siden det er relevant for lunge lyder.**

**free to attend -> can attend.**

#### Abnormal Sound Dataset

**Tittel er misvisende siden de fleste lydene er normale**

**been collected -> recorded**

**6009 men: kun menn?**

**Sjekk crackles paperet for detaljer om stetoskop og mikrofon. Viktig å liste produsent etc.**

**Table 3.1: nyttig med en kolonne for % fordeling**

**Table 3.1: sjekk med Hasse at det er OK å publisere disse tallene her.**

**...not had access to whole dataset...: We used a subset for this thesis.. Også er det viktig å spesifisere hva og hvor mange filer dette er.**

**Endel detaljer rundt metodologien mangler. Sjekk crackles for hva som bør være med.**

#### Breathing Phase Dataset

**...not from the same dataset...: høres ut som det finnes to lunge lyd datasett i T7.**

#### Training/test Partition

**side 29 er for det meste blank**

### ConvNet Design

*'Fig. 3.2 har veldig liten font**

### Wheeze Detection

**Tittel: Detection eller Classification? (ref diskusjonen i begynnelsen av Breathing Phase Detection).**

**best performing details -> ...model**

**of previous work -> of my previous work. Også en kort oppsumering om hva som ble gjort, og ikke gjort, i det arbeidet (det kommer senere, men bør tas rett etter at previous work blir nevnt)**

**prevelance...: mangler tall**

**Replicated related work...: hva ble gjort der? Leseren vil ikke orke å finne frem paperet og sjekke selv.**

**In the production stage (prototype): In the prototype. Og jeg skjønner ikke helt denne paragrafen. Antageligvis siden det er detaljer som Window size som ikke er forklart tidligere (ser etterpå at dette forklares i data preprocessing som kommer etterpå).**

**JC Aviles -> JC Aviles Solis**

**Fig 3.3: images are of size...pixels -> images are...pixels**

**Table 3.2: er utenfor margene (yay Latex!)**

### Breathing Phase Detection

**We also use a test set...not labeled..., this is bigger: skjønner ikke det som kommer etter "this is"**

**is also two loss functions -> are also...**

**Training parameters: Har du referanse for Approximaite joint training method & Alternating training? Eller er de del av ett framework?**

**Post-processing: ...that 11-15 second: språk**

**Post-processing: convert to excel -> ...to Excel**

**Post-processsing: the same style...: skriv om: The results are summarized in an Excel file.**

### Full file classification

**Full dataset/ Table 3.3: ble alle disse brukt i eksperimentene?**

### Experimental setup

**Running Ubuntu -> Operating System is Ubuntu..**

### Prototype

**Trenger bedre tittel. Jeg foretrekker application fremfor prototype.**

**after the evaluation of this thesis: bare sett en dato (tror sensur frist er 6 uker).**

**one month of usage: hva vil dette si? Det høres ut som det er en Heruko type betaling, men det korrekte er vel at du betaler per instanse uansett hvor lite eller mye de brukes.**

**Hvor mange samtidige brukere vil t2.medium støtte?**

#### Wheeze detection interface

**Her blir overskiften forvirende, siden interface allerede ble presenstert rett før denne. Så antageligivs er ikke Interface rette ordet. Eventuelt kan det legges en setning i beskrivelsen over om at det kommer mer detaljerte forklaring for denne og breathing phase senere.**

**Er det selvsagt hvordan confidence er regnet ut? Er det forklart før?**

#### Brathing phase detection interface

**Denne har ikke en tabell som wheezes med confidence?**

# 30.05.17

## Results

**Results are reported -> We report. Dvs active voice. Word sin grammar check tar alle passive voice problemene.**

**individual systems -> models? Bruk av system, model, approach, prototype er egentlig forvirende i denne thesis.**

**a metric inspired by: høres ut som du har funnet opp noe selv. Noe jeg håper du ikke har gjort.**

**Jeg synes fortsatt variasjon bør rapporters for hvert enkelt eksperiment siden den er så høy. Eller er det vanlig for slike paper å ikke gjøre det?**

### Wheeze detection

**Lastly, the best model...: her mangler det noen ord**

**Expert evaluation of ... has revealed: dette må sies klarere. Det er noe som ble gjort som en del av dette arbeidet. Så det er revealed. Også må du si hvordan det ble gjort og av hvem. Jeg synes at dette er noe som bør løftes mer frem. Gjerne som ett eget delkapittel, der du begynner å si hva resultatene i [65] var, hvordan expert evaluation ble gjort, hva slags problemer som ble oppdaget, og hva du derfor konkluderte med.**

#### Different window size

**Tittel: -> window size (selv om jeg fortsatt synes en konklusjons-tittel er best, ref tidligere kommentarer)**

**hence achieving -> hence reduce**

**Increasing...-> Increasing...has two/three advantages. First, ...**

**context of each ...event -> context for each**

**Wheeze events -> The...befor after a wheeze...is relevant**

**A small window...-> Talking noise may be similar to wheeze in small windows.**

**Larger windows...: kan tas bort siden den sier det samme som forrige setning.**

**On the other hand -> Increasing...has two disadvantages. First, ... Second. The right window choice therefore requires finding the right trade-off.**

**3 sec window: kan du si at du tror at forskjellen mellom 2 og 3 sec er så liten at det er bedre å bruke 2 siden den markerer wheeze mer nøyaktig? (du sier kanskje det allerede, men det er vanskelig å forstå eksakt hva som menes med: between coarse detections and ...)**

Kan window size endres dynamisk uten noe ekstra manuelt arbeid? I såfall er dette ett poeng å løfte opp her.

#### Ensemble ...

**We continue...: We use...ikke-experiment-men-model/result**

**Hva ble beskrvet i 3.3. Leseren husker ikke dette og vil ikke bla tilbake.**

**resolutions results in an increase of mean -> resolutions increase mean**

**We also see an incrase in precision -> Precision increase**

**The results show -> Skriv om som ett råd. Both techniques should therefore be used.**

#### Individual ...

**achieved and wheeze -> achieved wheeze**

**We that -> In addition, false positives is**

#### ...Previous work

**in previois -> in previously**

**Table 4.5: kan kutte ", which is a simple procedure...2.1.2"**

**Table 4.5: kanskje det ikke var så lurt å ta med always wheeze/normal. Random guess er nok tror jeg.**

**Again...to previous work: hvilken av de?**

**under the clinical -> for this setting/environment**

#### Performance

**Siden Performance kan bety mange ting i en slik oppgave liker jeg Speed-Performance bedre.**

### Breathing Phase...

In this experiemnt: Oppsumer først hva det var.

**Do note, that -> Note that the mean precision used in the above results and the ... (mAP) cannot be directly compared.**

**Faster R-CNN: hva slags data er Pascal VOC? Og er 78.8% regnet som veldig bra?**

**Før beskrivelsen av Fig 4.1: en setning om hvorfor du viser dette. Kanskje det også burde være en lignede figur for wheezes?**

**A phsiotherapist: litt mer hvem Cristina er slik at de ikke tror det var en du fant på gaten.**

**Some of this: Some of the missed phases were difficult for the expert to...**

**The results obtained...frequency analysis: hva frequency analysis? Og med mindre du ble å gjøre en slik analysis, synes jeg det er bedre å skrive om dette i Future Work, eventuelt Discussion.**


#### Performance

**Er tom**

### Full file classifcation

**Tittel: Har ikke store bokstaver i hvert ord (jeg liker det egentlig best slik)**

**is attractive: de to første motivasjons setningene kan flyttes til begynnelsen av Restults kapittelet.**

#### Under-sampling

**smaller amount of...giving 1-5 times more: henger ikke sammen**

**Table 3.3 kan enten flyttes hit eller kopieres her også.**

**Er det mulig å sammenlinge resultaten i 4.6 med noen naive metoder? Eller blir det meningsløst?**

**Hva er konklusjonen for disse resultatene?**

### Architectures

**Skulle vel være level-3 heading (dvs 4.3.2)**

**experiemnted with differnt architectures: for hva slags data? Dvs mangler en setning som knytter disse opp mot det ovenfor.**

**14ss arch v3 for further experiemnts: er ikke deete det siste eksperimentet?**

**VGGNet We believe ... -> VGGNet. We believe this is due to...**

**It is possible to use more ensemles: hvorfor er ikke det gjort?**

**do anything with this system: mer konkret. Hva kan den brukes til (her passer kanskje de motivasjons setningene i begynnelsen inn)**

#### Performance

Er tom.


**discuss problems -> discuss limitations**

potential of this thesis -> potential of our methods/approach

### ...Full file classifictaion

**Tittel: kan ta bort "Problems with"**

**find out what the problem is ->  solve this issue.**

**more interesting to know...occur: rather than?**

### Annotations

**We therefore estimate: hvordan? Det viker rart hvis det er du selv som har gjort dette estimatet.**

**Inspection has been done: av hvem? hvordan?**

**are in reality is just -> are just**

**some bias...in predictions: er det sikkert at dette vil gi bedre resultater? Kanskje har du plukket ut de enkleste wheezes og at de mer vanskelige kommer til å skape problemer.**

### Bigger...

**we will get access -> we plan to use (begge stedene)**

**detailed information -> additional data**

**exploring the relationship between...: ikke sikker på om jeg skjønner denne. Og om det er noe du ser at din approach kan utvides til?**

### Commercial Potential

**Tittel: Commercialization (siden dette er gjort og ikke bare ett potentisalle)**

**Her kan prosessene godt beskrives:
- Markedsundersøkelse er gjort
- En søknad ble skrvet
- Dere ga en pitch
- Og ikke minst, dere fikk 1M NOK til dette

private company -> startup**

### Manglende diskusjon

**Class imbalance: du har trent med 50-50% wheeze/normal mens den normale fordelingen er mye mer ubalansert. Einar har formeneinger om dette. Her er en diskusjon om dette i forbindelse med crackles paperet:**

**Hva kan vi anta ville skjedd hvis vi hadde trent med 5% crackles 95% normal?

[1:14]
Morten sier: "Den hadde sikkert aldri funnet noen crackles, fordi å alltid klassifisere normal vil gi 95% accuracy."

[1:15]
Det jeg lurer på med min manglende statistikk kunnskap er:

[1:15]
1. Ville det være bedre å trene med en 5%-95% fordeling crackles vs normal?

[1:15]
2. Bør vi ta med en setning eller to i crackles paperet om dette?

[1:15]
3. Kan du legge inn den setningen?

einar [1:29 PM]
Skal vi se

einar [1:38 PM]
Mye av dette blir filosofisk tror jeg. Det er jo sant som han sier at å alltid si normal gir 95% accuracy, men å ha en perfekt modell gir 100% accuracy. Spørsmålet er om man kunne klare å få noen ekstra  oppå de 95% ved å beholde den riktige fordelingen, hvilket er vanskelig å si uten å ha prøvd. Det man gjør vet å under-sample fra den store klassen er jo i og for seg å si at jeg er villig til å bygge en "feil" modell med flere false positives i håp om at vi også får noen ekstra true positives

[1:39]
Siden modellen er validert på kunstig balanserte data sier ikke de rapporterte tallene så mye om hva som vil skje i det virkelige liv

[1:39]
Som er grunnen til at man plages med mange false positives i hele lydfiler, gjetter jeg

[1:39]
så

[1:40]
1) jeg vill selv vært mere komfortabel med 95-5 split, men der er jo noe machine learning folklore som sier at kunsstig balansering er en naturlig ting å gjøre, så kanskje det er en kulturgreie

[1:41]
merk at man kunne fortsatt bestemme seg for samme tradeoff (flere false positives for å få flere true positives) ved andre midler

[1:42]
2) jeg ser nå at den setningen jeg har kommentert på faktisk henviser til dette (vi har ikke tenkt på hva som skjer under den naturlige ubalansen)

[1:42]
3) jeg skal se om jeg synes det skal skrives litt ekstra**

## Conclusion

**in many new technologies -> in many new fields/applications**

**A tempting -> An obvious**

**our systems is comparable to devices: results are comparable. Jeg synes du også kan si at du er like bra/ bedre en mennesker.**

**we will attempt -> we plan in our startup to**

### Future Work

**Ser du noen forskningsmuligheter som andre kan angripe?**

# 31.05.17

## Abstract

**Application of these methods...further evalutation and validation: her høres det ut som det bare er å ta en black box løsning og brukee det direkte, så jeg savner ordet som oppsumerer det som er gjort i Kap. 3.**

**This thesis proposes...called wheezes. Her savner jeg også 1-2 setninger som oppsumerer innholdet i Kap. 3. Dvs flere detaljer om metodene som er brukt.**

**Related work...mixture model: kan disse tre oppsumeres med 2-3 ord? non-deep-learning-machine learning.

Related work: her bør issues listes opp med related work, eventuelt fordeler med din approach.**

**ConvNets using spectograms....Tromsø study 7. Dette synes jeg ikke er bra beskrevet. Jeg tror det er bedre å liste 2-3 fordeler vs related work.**

**...we use the largest...: mangler tall. Og det høres ut som du kun sammenligner mot andre lunge lyd studier i T7.**

**Jeg synes du skal si at commercial potential er demonstrert og ført til en startup i siste paragraf.**


## Introduction

Merk at jeg leser en papir versjon skrevet ut ca 19:30, og har ikke sjekket om nyeste versjon har fikset det jeg kommentere.

1.§, siste setning: får ikke frem problemet med å bruke "large public dataset". Det høres jo som den beste måten å utivkle deep learning på.

1.§: savner 1-2 setninger om behovet for/ nytten av lunge lyd analyse. Men det passer kanskje ikke inn.

**2.§: de to siste setningene bør slås sammen. Blir mer klart da.**

Listen, punkt 1: fungerer ikke. To første setninger er om mennesker og ikke "developing deep learning". Og det er ikke en logisk sammenheng med siste setning (behovet for ref DB). Løsning: start med siste setning, og si hvrfor ref DB trenges. De to første setningene kan flyttes ett annet sted.

**Listen, punk 4: er "synthetic datasets" det beste ordet her?**

**Listen, punkt 5: er ikke behovet for GUI generelt også for ikke helse-folk? Behovet er vel for å hjelpe folk til å oppdage og tolke lydene siden din approach ikke på egen hånd kan diagnostisere pasienter.**


**"Existing systems focuses": alle gjør ikke nødvendigvis det, så "most existing..."**

"The methods have been trained...": mangler tall

"Our approach is as follows": denne er vanskelig å skjønne siden approach blir brukt om 3 eller 4 ting i resten av paragrafen. Innholdet er egentlig bra i de setningene, og ser man bort fra approah/system/prototype så gir det mening.

Contribtions listen: savner ett punkt om evaluation

### Problems with lung sound analysis

...(worsening of disease...): setningen henger ikke sammen

lung sound analysis systems is attractive: ikke attractive

### ConvNet using...

Tittel mangler ordet "anlysis" (eller noe bedre). Kanskje den kan skrives om til "ConvNet using Lung Sound Spectograms"

### Summary of results

**Jeg mener fortsatt at den demonstrerte "application" (LATT) er ett viktig resultat.**


## Bibliography

Tittel: -> References

1: mangler publikasjon. "in ...". St. Peter. Electr. Univ. kan fjernes

**23: 2 typos**

**25: virkerlig vol 1. no. 1?**

**30: W. Commons er en produktiv fyr. (<- spøk)**

**31: mangler publikasjon**

**32: trenger ikke å liste editors (i parantes)**

**41: noe galt med navnene**

**42: er denne blitt publisert enda (CoRR er ett preprint arkiv)**

**43: arXiv preprint arXiv**

**58: mangler publikasjons navn**

**67: mangler publikasjons navn**

**68: samme typo som for Morten sin thesis :)**

## Appendix B

har tomme del-kapitler
