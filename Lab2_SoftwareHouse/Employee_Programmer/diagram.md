```mermaid
classDiagram
    Employee <|-- Programmer
    SoftwareHouse o-- "0..*" Programmer : programers
```