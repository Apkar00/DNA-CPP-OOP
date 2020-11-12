# Class Diagram

```plantuml
class DNAseq{
    + getLength(): size_t
    - nueclotide: bitset<8>
    - my_seq_length: size_t
}

Class DNA_Manipulator{
    - &seq: DNAseq
    + slice() : DNAseq
    + replace(): DNAseq
    + pairing(): DNAseq
    + new() : DNAseq
    + dup() : DNAseq
}
DNA_Manipulator *--left-  DNAseq : composition


Class DNA_Search{
    - &seq: DNAseq
    + find(): size_t
    + find_all() : vector<size_t> 
    + count() :    int
    + find_consensus_seq() : vector<size_t>
}

DNA_Search *--right-  DNAseq : composition


Class File_Manipulator{
    - &seq: DNAseq
    + load(): void
    + save(): void
    + read(): void
    + write(): void

}

File_Manipulator *-up-  DNAseq : composition


Class Command_Control{
    - &seq: DNAseq
    + help() : void 
    + list() : void
    + show() : void 
    + quit(): void
}

 Command_Control*-down-  DNAseq : composition

```
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>


# Use-Case Diagram
```plantuml

:Scientist: as B
:Doctor: as C
:Programmer: as D
rectangle DnaResearch{
(loadDNAseq)->(FindallDnaSeq)
(FindallDnaSeq)->(sliceDnaSeq)
(ConcatDnaSeq)->(SaveDNAseq)
(sliceDnaSeq)->(ConcatDnaSeq)
}
B -up-> DnaResearch: genetic engineering
C -down-> DnaResearch: examine
D -left->DnaResearch: Creating UML
rectangle DnaResults{
(readDNAseq)->(listDNAseq)
(listDNAseq)->(countDNAseq)
(countDNAseq)->(pairDNAseq)
(pairDNAseq)->(quit)
}
C -up-> DnaResults: Find Cure 
D -left->DnaResults: Creating UML
```

<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>

# Package Diagram
```plantuml
package DNA {
    class DNASeq
    package GUI {
        Class CommandControl
    }
    package Manipulators {
        class DNA_Manipulator
        class DNA_Search
    }
    package Interaction {
        package DNAFiles {
            class File_Manipulator
            
        }
        interface Loadseq
        interface Saveseq
      
        Saveseq -up- DNAFiles
        Loadseq <-up- File_Manipulator
        Saveseq <-up- File_Manipulator

    }
    GUI -left-> Interaction
    Loadseq *-- DNA_Search
    Loadseq *-- DNA_Manipulator
    Saveseq *-- DNA_Manipulator
    DNASeq*--DNAFiles
}
DNASeq*--Manipulators
DNASeq*--CommandControl



