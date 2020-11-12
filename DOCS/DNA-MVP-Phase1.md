# Class Diagram

```plantuml
class DNAseq{
    + getName(): string
    + getID(): size_t
    + database: vector<DNAseq>
    - nueclotide: bitset<8>
}

Class DNA_Creation{
    - &seq: DNAseq
    + new() : DNAseq
    + dup() : DNAseq
    + search_in_database: bool
    + find_seq_by_name: string
}
DNA_Creation *--left->  DNAseq : composed+inherited

Class File_Manipulator{
    - &seq: DNAseq
    + load(): void
    + save(): void
    + read(): void
    + write(): void

}

File_Manipulator *-up-  DNAseq : composition

```
<br>
<br>
<br>
<br>
<br>
<br>
<br>
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



rectangle Area51Labs{

:Scientist: as B
rectangle DnaResults{
(Load and Examine)
(quit)
rectangle Creating-Clone{
(loadDNAseq)
(CreateNew)
(DuplicateDna)
(SaveProgress)
}
B -up-> DnaResults: genetic engineering


```
<br>
<br>
<br>
<br>
<br>
<br>
<br>
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
        class DNA_Create
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
    GUI -up-> Interaction
    Loadseq *-- DNA_Create
    Saveseq *-- DNA_Create
}
DNASeq*--Manipulators
DNASeq*--CommandControl
DNASeq*--File_Manipulator
```
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>

# Deployment Diagram
```plantuml
package DNA-Application {
    package GUI {
        class README
    }
  
    package Interaction {
        package DNAproject {
        object DNA.o
            
        }
    
    }
    GUI -up-> Interaction
   
}

