```mermaid
classDiagram
    Programmer <|-- Employee
    ProjectLeader <|-- Programmer
    ProjectLeader "1" -- "0..*" Programmer : team 
    SoftwareHouse o-- "0..*" ProjectLeader : projectLeaders
    SoftwareHouse o-- "0..*" Programmer : programmers
```