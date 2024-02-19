/*
Rev: Ido Isaacs, Ido Peled.
Dev: Leonid Golovko
status: finished
date: 05/09/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct PublicTransport public_transport_t;
typedef struct Minibus minibus_t;
typedef struct ArmyMinibus army_minibus_t;
typedef struct Taxi taxi_t;
typedef struct SpecialTaxi special_taxi_t;
typedef struct PublicConvoy public_convoy_t;
typedef void (*public_ptr)(public_transport_t *);

void PublicTransportCtor(public_transport_t *this);
void PublicTransportDtor(public_transport_t *this); /*class type*/
void PublicTransportCCtor(public_transport_t *this ,const public_transport_t *other);
void PublicTransportdisplay(public_transport_t *this);
void PublicTransportPrintCount();
int PublicTransporGetID(public_transport_t *this);
void PublicTransportPrintCountNoVar(void);

void MinibusCtor(minibus_t *this);
void MinibusCCtor(minibus_t *this, const minibus_t *other);
void MinibusDtor(minibus_t *this);
void MinibusDisplay(minibus_t *this);
void MinibusWash(minibus_t *this, int minutes);


void ArmyMinibusCtor(army_minibus_t *this);
void ArmyMinibusCCtor(army_minibus_t *this,const army_minibus_t *other);
void ArmyMinibusDtor(army_minibus_t *this);

void TaxiCtor(taxi_t *this);
void TaxiCCtor(taxi_t *this,const taxi_t *other);
void TaxiDtor(taxi_t *this);
void TaxiDisplay(taxi_t *this);

void SpecialTaxiCtor(special_taxi_t *this);
void SpecialTaxiCCtor(special_taxi_t *this,const special_taxi_t *other);
void SpecialTaxiDtor(special_taxi_t *this);
void SpecialTaxiDisplay(special_taxi_t *this);

void PublicConvoyCtor(public_convoy_t* this);
void PublicConvoyCCtor(public_convoy_t* this ,public_convoy_t* other);
void PublicConvoyDtor(public_convoy_t* this);
void PublicConvoyDisplay(public_convoy_t* this);


int s_count_global = 0;

/*Structs and Vtables*/
/*PublicTransport*/

struct PublicTransport
{
    struct TransportVptr *vptr;
	int m_license_plate;
};

struct TransportVptr
{
    void (*display)(public_transport_t *);
    void (*dtor)(public_transport_t *);
}transport_sptr_t = {(void (*)(public_transport_t *))&PublicTransportdisplay, (void (*)(public_transport_t *))&PublicTransportDtor};
/*Minibus*/

struct Minibus
{
    public_transport_t parent;
	int m_numSeats;
};

struct MinibusVptr
{
    struct TransportVptr parent;
    void (*wash)(minibus_t *, int);
}minibus_sptr_t = {{((void (*)(public_transport_t *))&MinibusDisplay), ((void (*)(public_transport_t *))&MinibusDtor)}, &MinibusWash};


/*Army Minibus*/

struct ArmyMinibusVptr
{
    struct MinibusVptr parent;
}army_minibus_sptr_t = {{{((void (*)(public_transport_t *))&MinibusDisplay), ((void (*)(public_transport_t *))&MinibusDtor)}, &MinibusWash}};  
    

struct ArmyMinibus
{
    minibus_t parent;
};

/*Taxi*/

struct Taxi
{
    public_transport_t parent;
};

struct TaxiVptr
{
    struct TransportVptr parent;
}taxi_sptr_t = {{((void (*)(public_transport_t *))&TaxiDisplay), ((void (*)(public_transport_t *))&TaxiDtor)}};

/*Special Taxi*/

struct SpecialTaxi
{
    taxi_t parent;
};


struct TransportVptr special_taxi_sptr_t  = {(public_ptr)&SpecialTaxiDisplay, (public_ptr)&SpecialTaxiDtor};

struct TransportVptr convoy_sptr_t  = {(public_ptr)&PublicConvoyDisplay, (public_ptr)&PublicConvoyDtor};

struct PublicConvoy
{
    public_transport_t parent;
    public_transport_t *m_pt1;
    public_transport_t *m_pt2;
    minibus_t m_m;
    taxi_t m_t;
};

/*Function implementation*/
/*PublicConvoy*/

void PublicConvoyCtor(public_convoy_t* this)
{
    PublicTransportCtor(&this->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &convoy_sptr_t;
    this->m_pt1 = (public_transport_t*)malloc(sizeof(minibus_t));
    MinibusCtor((minibus_t *)this->m_pt1);
    this->m_pt2 = (public_transport_t*)malloc(sizeof(taxi_t));
    TaxiCtor((taxi_t *)this->m_pt2);
    MinibusCtor(&this->m_m);
    TaxiCtor(&this->m_t);
    printf("PublicConvoy::Ctor()\n");
}
void PublicConvoyCCtor(public_convoy_t* this ,public_convoy_t* other) 
{
    PublicTransportCCtor(&this->parent, &other->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &convoy_sptr_t;
    this->m_pt1 = (public_transport_t*)malloc(sizeof(minibus_t));
    MinibusCCtor((minibus_t *)this->m_pt1  ,(minibus_t *)other->m_pt1);
    this->m_pt2 = (public_transport_t*)malloc(sizeof(taxi_t));
    TaxiCCtor((taxi_t *)this->m_pt2 ,(taxi_t *)other->m_pt2);
    MinibusCCtor(&this->m_m, &other->m_m);
    TaxiCCtor(&this->m_t, &other->m_t);
    printf("PublicConvoy::CCtor()\n");
}

void PublicConvoyDtor(public_convoy_t* this)
{
    
    MinibusDtor((minibus_t *)this->m_pt1);
    free(this->m_pt1);
    TaxiDtor((taxi_t *)this->m_pt2);
    free(this->m_pt2);
    printf("PublicConvoy::Dtor()\n");
    TaxiDtor(&this->m_t);
    MinibusDtor(&this->m_m);
    PublicTransportDtor(&this->parent);
    
}

void PublicConvoyDisplay(public_convoy_t* this)
{
    this->m_pt1->vptr->display(this->m_pt1);
    this->m_pt2->vptr->display(this->m_pt2);
    /* this->m_m.parent.vptr->display((public_transport_t *)&this->m_m);
    this->m_t.parent.vptr->display((public_transport_t *)&this->m_t); */
    /*call function itself*/
    MinibusDisplay(&this->m_m);
    TaxiDisplay(&this->m_t);

}

/*PublicTransport*/

void PublicTransportCtor(public_transport_t *this)
{
    ++s_count_global;
    this->m_license_plate = s_count_global;
    this->vptr = &transport_sptr_t;
    printf("PublicTransport::Ctor()%d\n", this->m_license_plate);
    return;      
}

void PublicTransportDtor(public_transport_t *this)
{
    --s_count_global;
    printf("PublicTransport::Dtor()%d\n", this->m_license_plate); 
    return;
}

void PublicTransportCCtor(public_transport_t *this ,const public_transport_t *other)
{
    ++s_count_global;
	this->m_license_plate = s_count_global;
    this->vptr = other->vptr;
	printf("PublicTransport::CCtor() %d\n", this->m_license_plate);
}

void PublicTransportdisplay(public_transport_t *this)
{
    printf("PublicTransport::display(): %d\n", this->m_license_plate);
}

void PublicTransportPrintCount()
{
    printf("s_count: %d\n", s_count_global);
}

int PublicTransporGetID(public_transport_t *this)
{
    return this->m_license_plate;
}

void PublicTransportPrintCountNoVar(void)
{
    printf("s_count: %d\n", s_count_global);
}

/*Minibus*/

void MinibusCtor(minibus_t *this)
{
    PublicTransportCtor(&this->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &minibus_sptr_t;
    s_count_global = this->parent.m_license_plate;
    this->m_numSeats = 20;
    printf("Minibus::Ctor()\n"); 
    return;
}

void MinibusCCtor(minibus_t *this,const minibus_t *other)
{

    PublicTransportCCtor(&this->parent, &other->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &minibus_sptr_t;
    this->m_numSeats = other->m_numSeats;
    printf("Minibus::CCtor()\n");
}

void MinibusDtor(minibus_t *this)
{
    printf("Minibus::Dtor()\n");
    PublicTransportDtor(&this->parent);
}

void MinibusDisplay(minibus_t *this)
{
    printf("Minibus::display() ID:%d", this->parent.m_license_plate);
    printf(" num seats:%d\n", this->m_numSeats);
}

void MinibusWash(minibus_t *this, int minutes)
{
    printf("Minibus::wash(%d) ID:%d\n",minutes, PublicTransporGetID(&this->parent));
}
    
/*Army Minibus*/

void ArmyMinibusCtor(army_minibus_t *this)
{
    MinibusCtor(&this->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &minibus_sptr_t;
    printf("ArmyMinibus::Ctor()\n");
}

void ArmyMinibusCCtor(army_minibus_t *this,const army_minibus_t *other)
{
    MinibusCCtor(&this->parent, &other->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &army_minibus_sptr_t;
    printf("ArmyMinibus::CCtor()\n");
}

void ArmyMinibusDtor(army_minibus_t *this)
{
    printf("ArmyMinibus::Dtor()\n");
    MinibusDtor(&this->parent);
}

/*Taxi*/

void TaxiCtor(taxi_t *this)
{
    PublicTransportCtor(&this->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &taxi_sptr_t;
    printf("Taxi::Ctor()\n");
}

void TaxiCCtor(taxi_t *this,const taxi_t *other)
{
    PublicTransportCCtor(&this->parent ,&other->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &taxi_sptr_t;
    printf("Taxi::CCtor()\n");
}

void TaxiDtor(taxi_t *this)
{
    printf("Taxi::Dtor()\n");
    PublicTransportDtor(&this->parent);
}

void TaxiDisplay(taxi_t *this)
{
    printf("Taxi::display() ID:%d\n", this->parent.m_license_plate);
}

/*Special Taxi*/

void SpecialTaxiCtor(special_taxi_t *this)
{
    TaxiCtor(&this->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &special_taxi_sptr_t;
    printf("SpecialTaxi::Ctor()\n");
}

void SpecialTaxiCCtor(special_taxi_t *this,const special_taxi_t *other)
{
    TaxiCCtor(&this->parent, &other->parent);
    ((public_transport_t *) this)->vptr = (struct TransportVptr *) &special_taxi_sptr_t;
    printf("SpecialTaxi::CCtor()\n");
}

void SpecialTaxiDtor(special_taxi_t *this)
{
    printf("SpecialTaxi::Dtor()\n");
    TaxiDtor(&this->parent);
}

void SpecialTaxiDisplay(special_taxi_t *this)
{
    printf("SpecialTaxi::display() ID:%d\n", this->parent.parent.m_license_plate);
}
    
    
    
int MaxFunc(int t1, int t2)
{
    return ((t1 > t2) ? t1 : t2);
}

void PrintInfo(public_transport_t *this)
{
    PublicTransportdisplay(this);
}

void PrintInfoWithNoData()
{
    PublicTransportPrintCountNoVar();
}

void PrintInfoMinibus(minibus_t *this)
{
    MinibusWash(this, 3);
}

public_transport_t PrintInfoWithInteger(int i)
{
    minibus_t ret;
    public_transport_t return_value;
    (void)i;
    MinibusCtor(&ret);
    printf("print_info(int i)\n");
    MinibusDisplay(&ret);
    
    PublicTransportCCtor(&return_value, &ret.parent);
    MinibusDtor(&ret);
    PublicTransportdisplay(&return_value);
    return return_value;
}

void TaxiDisplayByValue(taxi_t s)
{
    TaxiDisplay(&s);
}

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    minibus_t m;
    public_transport_t return_value;
    public_transport_t *array[3];
    minibus_t minibus3;
    taxi_t taxi2; 
    public_transport_t arr2[3];
    minibus_t m2;
    minibus_t arr3[4];
    taxi_t *arr4 = NULL;
    special_taxi_t st;
    taxi_t temp;
    army_minibus_t *army_minibus = NULL;
    public_convoy_t *ts1 = NULL;
    public_convoy_t *ts2 = NULL;

    (void)argc;
    (void)argv;
    (void)envp;
    MinibusCtor(&m);
    PrintInfoMinibus(&m);
    return_value = PrintInfoWithInteger(3);
    PublicTransportDtor(&return_value);

    array[0] = (public_transport_t *)malloc(sizeof(minibus_t));
    array[1] = (public_transport_t *)malloc(sizeof(taxi_t));
    array[2] = (public_transport_t *)malloc(sizeof(minibus_t));
    MinibusCtor((minibus_t *)array[0]);
    TaxiCtor((taxi_t *)array[1]);
    MinibusCtor((minibus_t *)array[2]);

    for (i = 0; i < 3; ++i) 
    {
        array[i]->vptr->display(array[i]);
    }

    for (i = 0; i < 3; ++i) 
    {
        array[i]->vptr->dtor(array[i]);
        free(array[i]);
    }

    
    MinibusCtor(&minibus3);
    PublicTransportCCtor(&arr2[0], (public_transport_t *)&minibus3);
    MinibusDtor(&minibus3);
    TaxiCtor(&taxi2);
    PublicTransportCCtor(&arr2[1], (public_transport_t *)&minibus3);
    TaxiDtor(&taxi2);
    PublicTransportCtor(&arr2[2]);
    
    for (i = 0; i < 3; ++i) 
    {
        PublicTransportdisplay(&arr2[i]);
    }
    PrintInfo(&arr2[0]);

    PrintInfoWithNoData();
    
    MinibusCtor(&m2);
    PublicTransportPrintCountNoVar();

    for(i = 0; i < 4; ++i)
    {
        MinibusCtor(&arr3[i]);
    }
    arr4 = (taxi_t *)malloc(sizeof(taxi_t) * 4);
    for(i = 0; i < 4; ++i)
    {
        TaxiCtor(&arr4[i]);
    }
    for(i = 3; i >= 0; --i)
    {
        TaxiDtor(&arr4[i]);
    }
    free(arr4);

    printf("%d\n", MaxFunc(1, 2));
    printf("%d\n", MaxFunc(1, (int)2.0f));

    SpecialTaxiCtor(&st);
    TaxiCCtor(&temp, &st.parent);
    TaxiDisplayByValue(temp);
    TaxiDtor(&temp);

    ts1 = (public_convoy_t *)malloc(sizeof(public_convoy_t));
    PublicConvoyCtor(ts1);
    ts2 = (public_convoy_t *)malloc(sizeof(public_convoy_t));
    PublicConvoyCCtor(ts2, ts1);
    ts1->parent.vptr->display((public_transport_t *)ts1);
    
    ts2->parent.vptr->display((public_transport_t *)ts2);
    
    ts1->parent.vptr->dtor((public_transport_t *)ts1);
    free(ts1);
    ts2->parent.vptr->display((public_transport_t *)ts2);
    
    ts2->parent.vptr->dtor((public_transport_t *)ts2);
    free(ts2);
 
    army_minibus = (army_minibus_t *)malloc(sizeof(army_minibus_t));
    ArmyMinibusCtor(army_minibus);
    ((minibus_t *)army_minibus)->parent.vptr->display((public_transport_t *)army_minibus);
    ((struct MinibusVptr *)(((public_transport_t *)army_minibus)->vptr))->wash((minibus_t*)army_minibus, 5);
    ArmyMinibusDtor(army_minibus);
    free(army_minibus);

    
    SpecialTaxiDtor(&st);
    
    for(i = 3; i >= 0; --i)
    {
        MinibusDtor(&arr3[i]);
    }
    
    MinibusDtor(&m2);
    
    for(i = 2; i >= 0; --i)
    {
        PublicTransportDtor(&arr2[i]);
    }
    
    MinibusDtor(&m);
    return 0;
}


