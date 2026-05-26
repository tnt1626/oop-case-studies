```mermaid
classDiagram
    SoftwareHouse "1" o-- "0...*" Employee : staff
    Employee <|-- Administrator
    Employee <|-- Programmer
    Programmer <|-- ProjectLeader
    ProjectLeader "1" -- "0..*" Programmer: team

    class Employee {
        <<abstract>>
    }
```