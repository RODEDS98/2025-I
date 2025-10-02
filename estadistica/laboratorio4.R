---
title: "control2prueba"
author: "Edgard Rodriguez V"
date: "2025-10-01"
output: html_document
---
```{r}
#install.packages("openxlsx")
library(openxlsx)
#install.packages("openintro")
#library(openintro)
#Importacion del excel:

```

<p> En una empresa del total de trabajadores, se tiene que el 50% son técnicos profesionales, el 30% son oficinistas y el 20% personal de servicio; además se tiene que el 8% de los profesionales, 9% de los oficinistas y el 10% del personal de servicio, son provincianos (nacidos fuera de Arequipa).
Supóngase que se selecciona un trabajador al azar y resulta ser provinciano.
Calcular la probabilidad de que el trabajador sea Técnico Profesional </p>

```{r}
treeDiag(
  c("1","2"),
  p1 = c( 0.5 , 0.3 , 0.2 ),
  p2 = list( round( c(0.08,0.92),3),round( c(0.09,0.91),3 ),round( c(0.10,0.90),3 )),
  out1 = c("TP","O","PS"),
  out2 = c("PROVINCIA","NO_PROVINCIA")
)
```


Calcular la probabilidad de que el trabajador sea Técnico Profesional

```{r}

#Primero: hallamos la probabilidad de que sea provinciano
Probabilidad_P <- sum( 0.04 , 0.027 , 0.02)
Probabilidad_P

#Segundo: hallamos la probabilidad de que el tecnico sea profesional y sea provinciano (TP . P)
Probabilidad_TP_P <- 0.04

#Tercero: hallamos la probabilidad de que el tecnico sea profesional  (TP/P)

P <- Probabilidad_TP_P/Probabilidad_P
P
```

Calcular la probabilidad de que el trabajador sea Técnico Profesional
La probabilidad de que el trabajador sea Técnico Profesional es de 0.4597701



Los clientes se encargan de evaluar los diseños preliminares de varios productos. En el pasado el 95%
de los productos que con mayor éxito en el mercado recibieron buenas evaluaciones, el 60% de los
productos con éxito moderado recibieron buenas evaluaciones, el 10% de productos de escaso éxito
recibieron buenas evaluaciones. Además, el 40% de los productos han tenido mucho éxito, el 35%
un éxito moderado y el 25% una baja aceptación.

```{r}
treeDiag(
  c(1,2),
  p1 = c( 0.4 , 0.35 , 0.25 ),
  p2 = list( round( c(0.95,0.05),3),round( c(0.6,0.4),3 ),round( c(0.10,0.90),3 )),
  out1 = c("M E","E M","B A"),
  out2 = c("BUENAS E","NO BUENAS E")
)

```


a) ¿Cuál es la probabilidad de que un producto obtenga una buena evaluación?

```{r}
#Primero: hallamos la probabilidad de que los productos tengan una buena evaluacion
Probabilidad_BE <- sum( 0.38 , 0.21 , 0.025)
Probabilidad_BE

```

b) Si un nuevo diseño obtiene una buena evaluación, ¿Cuál es la probabilidad de que se convierta
en un producto de gran éxito?

```{r}

#Primero: hallamos la probabilidad de que los productos tengan una buena evaluacion
Probabilidad_BE <- sum( 0.38 , 0.21 , 0.025)

#Segundo: hallamos la probabilidad de que sea un producto de gran exito y tenga buena evaluacion (ME . BE)
Probabilidad_ME_BE <- 0.38

#Tercero:  hallamos la probabilidad de que sea un producto de gran exito dado tenga buena evaluacion (ME/BE)
q <- Probabilidad_ME_BE/Probabilidad_BE
q

```
c) Si un producto no obtiene una buena evaluación. ¿Cuál es la probabilidad de que se convierta en
un producto de gran éxito?

```{r}
#Primero: hallamos la probabilidad de que los productos tengan una buena evaluacion
Probabilidad_NBE <- 1-sum( 0.38 , 0.21 , 0.025)

#Segundo: hallamos la probabilidad de que sea un producto de gran exito y tenga buena evaluacion (ME . NBE)
Probabilidad_ME_NBE <- 0.02

#Tercero:  hallamos la probabilidad de que sea un producto de gran exito dado tenga buena evaluacion (ME/BE)
r <- Probabilidad_ME_NBE/Probabilidad_NBE
r
```



