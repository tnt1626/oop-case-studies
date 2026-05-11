```mermaid
classDiagram
    Employee <|-- Programmer
    Programmer <|-- ProjectLeader

    SoftwareHouse o-- "0..*" Programmer : staff

    ProjectLeader "1" -- "0..*" Programmer : team
```