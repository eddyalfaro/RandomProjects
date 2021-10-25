#include "OversizeArr.h"
#include <stdio.h>
#include <math.h>

#define _A(value) (value > 48.0)
#define _B(value) (value < 100.0)
#define _C(value) (value > 43.0 && value < 160.0)

using namespace std;

OverArray<float>* getData(){
    float _temp;
    OverArray<float>* _data = new OverArray<float>();
    while (scanf("%f", &_temp) > 0) _data->add(_temp);

    return _data;
}

int compare(float _lhs, float _rhs){
    if (_lhs > _rhs) return 1;
    else if (_lhs < _rhs) return -1;
    
    return 0;
}

int main(){
    cout << "--Problem 2.34--" << endl;
    OverArray<float>* _data = getData();
    float min = _data->get(0), max = _data->get(0);

    for (int i = 1; i < _data->lenght; i++){
        if (min > _data->get(i)) min = _data->get(i);
        if (max < _data->get(i)) max = _data->get(i);
    }

    int _intervals = 1 + 3.322*log10(_data->lenght);
    float _remainder = 1 + 3.322*log10(_data->lenght) - _intervals;

    if (_remainder > 0.5) _intervals++;
    else if (_remainder == 0.5 && _intervals%2 == 1) _intervals++;

    printf("MAX = %f, MIN = %f, #INTERVALS = %d\n", max, min, _intervals);

    OverArray<float> _limits, _frequency, _relFreq;
    for (int i = 0; i < _intervals + 1; i++) _limits.add(min + i*(max - min)/_intervals);
    cout << "Class Intervals: " << _limits;

    int freqCnt;
    for (int i = 0; i < _limits.lenght - 1; i++){
        freqCnt = 0;
        for (int j = 0; j < _data->lenght; j++){
            if (_data->get(j) >= _limits.get(i) && _data->get(j) < _limits.get(i+1)) freqCnt++;
        }

        if (i == _limits.lenght - 2) freqCnt++;
        _frequency.add(freqCnt);
        _relFreq.add((float) freqCnt / _data->lenght);
    }

    cout << "Frequency: " << _frequency;
    cout << "Relative Frequency: " << _relFreq << endl;

    printf("|---Class intervals (MStb)---|--Class Mark--|--Frequency--|--Cum Freq--|--Rel Freq--|--Cum Rel Freq--|--Decu Rel Freq--|\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    float cum = 0, decum = 100;
    float cumFreq = 0;
    for(int i = 0; i < _limits.lenght - 1; i++){
        cum += 100 * _relFreq.get(i);
        decum -= 100 * _relFreq.get(i);
        cumFreq += _frequency.get(i);

        if (i == _limits.lenght - 2)
                printf("| \t[%4.2f , %4.2f] \t|   %.2f   |   %.0f  |   %.0f   |   %.2f   |   %.2f   |   %.2f   |\n", _limits.get(i), _limits.get(i + 1), (_limits.get(i)+_limits.get(i + 1))/2, 
            _frequency.get(i), cumFreq, _relFreq.get(i) * 100, cum, decum);
        else printf("| \t[%4.2f , %4.2f) \t|   %.2f   |   %.0f  |   %.0f   |   %.2f   |   %.2f   |   %.2f   |\n", _limits.get(i), _limits.get(i + 1), (_limits.get(i)+_limits.get(i + 1))/2, 
            _frequency.get(i), cumFreq, _relFreq.get(i) * 100, cum, decum);
    }

    printf("------------------------------------------------------------------------------------------------------------------------\n");


    cout << endl;
    printf("Lower interval (MStb), Upper interval (Mstb),Class Mark (Mstb),Frequency,Cum Freq,Rel Freq,Cum Rel Freq,Decu Rel Freq\n");
    cum = 0, decum = 1;
    cumFreq = 0;
    for(int i = 0; i < _limits.lenght - 1; i++){
        cum += _relFreq.get(i);
        decum -= _relFreq.get(i);
        cumFreq += _frequency.get(i);

        printf("%4.2f , %4.2f,   %.2f  ,   %.0f  ,  %.0f  ,   %.2f   ,  %.2f   ,  %.2f \n", _limits.get(i), _limits.get(i + 1), (_limits.get(i)+_limits.get(i + 1))/2, 
            _frequency.get(i), cumFreq, _relFreq.get(i), cum, decum);
    }

    cout << endl << endl;

    int _aCnt = 0, _bCnt = 0, _cCnt = 0;

    for (int i = 0; i < _data->lenght; i++){
        if (_A(_data->get(i))) _aCnt++;
        if (_B(_data->get(i))) _bCnt++;
        if (_C(_data->get(i))) _cCnt++;
    }

    cout << "P(Np > 48 MStb) = " << 100 * ((float) _aCnt / _data->lenght) << "%" << endl;
    cout << "P(Np < 100 MStb) = " << 100 * ((float) _bCnt / _data->lenght) << "%" << endl;    
    cout << "P(43 MStb < Np < 160 MStb) = " << 100 * ((float) _cCnt / _data->lenght) << "%" << endl;


    cout << "\n---Problem 2.35--- UNGROUPED DATA" << endl;
    _data->organize(compare);
    _data->add(max);

    OverArray<float>* _copy  = new OverArray<float>(_data);

    float sum = 0;
    for (int i = 0; i < _copy->lenght; i++) sum += _copy->get(i);
    printf("Mean of sample: %.2f Mstb\n", sum/_copy->lenght);
    printf("Median of sample: %.2f Mstb\n", _copy->get(_copy->lenght/2));

    OverArray<float> _val;
    OverArray<int> _rep;

    int i = 0, j = 1, count = 0;
    while (j < _copy->lenght){
        count = 0;
        _val.add(_copy->get(i));
        
        for (j; j < _copy->lenght; j++){
            if (_val.getLast() == _copy->get(j)) count++;
            else break;
        }

        _rep.add(count);
        i = j;
        j++;
    }

    if (i == _copy->lenght - 1) {_val.add(_copy->getLast()); _rep.add(0);}

    int _repMax = 0;
    for (i = 0; i < _rep.lenght; i++){
        if (_rep.get(i) > _repMax) _repMax = _rep.get(i);
    }

    for (i = _rep.lenght - 1; i >= 0; i--){
        if (_rep.get(i) < _repMax) {_rep.remove(i); _val.remove(i);}
    }
    
    printf("Sample has %d modes (Mstb): ", _rep.lenght);
    cout << _val << endl;

    float _mean = sum/_data->lenght;
    float _var = 0;

    float _geoSum = 0, _harSum = 0, _quaSum = 0;
    for (int i = 0; i < _data->lenght; i++) {
        _var += (_mean - _data->get(i)) * (_mean - _data->get(i));
        _geoSum += log10(_data->get(i));
        _harSum += 1.0/_data->get(i);
        _quaSum += _data->get(i) * _data->get(i);
    }

    _var = _var / _data->lenght;
    float _sd = sqrt(_var);

    printf("Variance of the Sample: %.2f MStb^2\n", _var);
    printf("Standard Deviation of the Sample: +/- %.2f MStb\n", _sd);
    printf("Coefficient of variation of the Sample: %.2f\n", 100 * _sd/_mean);

    cout << endl;
    printf("Geometric Mean of Sample: %.2f MStb\n", pow(10.0, _geoSum/_data->lenght));
    printf("Harmonic mean of sample: %.2f MStb\n", _data->lenght/_harSum);
    printf("Quadratic mean of sample: %.2f MStb\n", sqrt(_quaSum/_data->lenght) );

    cout << endl;
    cout << "---Problem 2.36--- GROUPED DATA" << endl;

    sum = 0, cum = 0;
    int _maxFreq = 0, _ulMedian = 0;
    _var = 0, _geoSum = 0, _harSum = 0;
    for (i = 0; i < _relFreq.lenght; i++){
        if (cum < 0.5) {cum += _relFreq.get(i); _ulMedian = i;}
        if (_frequency.get(i) > _frequency.get(_maxFreq)) _maxFreq = i;
        sum += _relFreq.get(i) * (_limits.get(i) + _limits.get(i + 1))/2;

        _var += _relFreq.get(i) * pow((_limits.get(i) + _limits.get(i + 1))/2, 2);
        _geoSum += _relFreq.get(i) * log10((_limits.get(i) + _limits.get(i + 1))/2);
        _harSum += _relFreq.get(i) / ((_limits.get(i) + _limits.get(i + 1))/2);
    }

    _var -= pow(sum, 2);
    _sd = sqrt(_var);

    float _Ul = (_limits.get(_ulMedian) + _limits.get(_ulMedian + 1))/2;
    float _Ll = (_limits.get(_ulMedian - 1) + _limits.get(_ulMedian))/2;

    float _median = (0.5 - (cum - _relFreq.get(_ulMedian))) * (_Ul - _Ll) / (_relFreq.get(_ulMedian)) + _Ll;
    printf("Mean of Sample: %.2f Mstb\n", sum);
    printf("Mode of Sample: %.2f MStb\n", (_limits.get(_maxFreq) + _limits.get(_maxFreq + 1))/2);
    printf("Median of Sample: %.2f MStb\n", _median);

    cout << endl;
    printf("Variance of the Sample: %.2f MStb^2\n", _var);
    printf("Standard Deviation of the Sample: +/- %.2f MStb\n", _sd);
    printf("Coefficient of variation of the Sample: %.2f\n", 100 * _sd/_mean);

    cout << endl;
    printf("Geometric Mean of Sample: %.2f MStb\n", pow(10.0, _geoSum));
    printf("Harmonic mean of sample: %.2f MStb\n", 1/_harSum);

    delete _data;
    delete _copy;
    return 0;
}